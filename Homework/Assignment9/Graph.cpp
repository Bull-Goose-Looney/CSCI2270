#include "Graph.hpp"
#include <queue>
#include <iostream>
#include <string>
using namespace std;

// Connects v1 and v2 to eachother.
void Graph::addEdge(string v1, string v2) {
	//Loop through Vertices (nodes);
	for(int i = 0; i < vertices.size(); i++) {
		if(vertices[i]->name == v1) { // Find v1
			for(int j = 0; j < vertices.size(); j++) { // Find v2 if v1 is found
				if(vertices[j]->name == v2 && i != j) {
					adjVertex ad; // New Vertex Pointer;
					ad.v = vertices[j]; // Vertex pointer = v2
					vertices[i]->adj.push_back(ad); // Add v2 to V1's connections
					adjVertex ad2; // New Vertex Pointer(v1)
					ad2.v = vertices[i]; // Vertex = v1
					vertices[j]->adj.push_back(ad2); // ad v1 to v2's connections
				}
			}
		}
	}
}

void Graph::addVertex(string name) {
	bool exists = false;
	/* Loop through vector of vertices and don't
	add the new vertex if it's already there */
	for(int i = 0; i <vertices.size(); i++) {
		if(vertices[i]->name==name)
			exists = true;
	}
	// If it doesn't yet exist, add it to the vertices vector.
	if(exists == false) {
		vertex *nVert = new vertex;
		nVert->name = name;
		vertices.push_back(nVert);
	}
}

void Graph::displayEdges() {
	int vSize = vertices.size();
	int adjSize;

	for(int i = 0;i < vSize; i++) {
		if(i > 0)
			cout << endl;
		cout << vertices[i]->name << " --> ";
		adjSize = vertices[i]->adj.size();

		for(int j = 0;j < adjSize; j++)
			cout << vertices[i]->adj[j].v->name <<" ";
	}
}

void Graph::breadthFirstTraverse(string sourceVertex) {
	vertex *vRoot;
	int vSize = vertices.size();
	int adjSize;

	for(int i = 0; i < vSize; i++)
	{
		if(vertices[i]->name==sourceVertex)
			vRoot = vertices[i];
	}
	vRoot->visited=true;

	queue<vertex*> q;
	q.push(vRoot);
	vertex *n;

	cout << "Starting vertex (root): ";
	cout << vRoot->name << "-> ";

	while(!q.empty())
	{
		n=q.front();
		adjSize = n->adj.size();
		q.pop();

		for(int i = 0; i < adjSize;i++)
		{
	       if(!n->adj[i].v->visited) {
              n->adj[i].v->visited = true;
              q.push(n->adj[i].v);
              n->adj[i].v->distance = n->distance+1;
              cout << n->adj[i].v->name << "(";
              cout << n->adj[i].v->distance << ")" << " ";
          	}
		}
	}
}

void bft(string name, vector<vertex*>vertices) {

	vertex *vRoot;
	int vSize = vertices.size();
	int adjSize;

	for(int i = 0; i < vSize; i++)
	{
		if(vertices[i]->name==name)
			vRoot = vertices[i];
	}
	vRoot->visited=true;

	queue<vertex*> q;
	q.push(vRoot);
	vertex *n;

	while(!q.empty())
	{
		n=q.front();
		adjSize = n->adj.size();
		q.pop();

		for(int i = 0; i < adjSize;i++) {

    	   if(!n->adj[i].v->visited) {
           n->adj[i].v->visited = true;
           q.push(n->adj[i].v);
           n->adj[i].v->distance = n->distance+1;
    		}
		}
	}
}

int Graph::getConnectedComponents() {
	/* 1. Pick a starting Vertex
			-Doesnt matter which, start with first in list
		2.	Initialize a counter. (int numSubGraphs = 0)
		3. Invoke a traversal (BFT or DFT)
			-Doesn't matter as long as every node is visited.
		4. Increment number of numSubGraphs
		5. Go back to vertices list and see if there are any unvisited.
			-Go back to step three if there are any unvisited.
		6. It will be done when every node in list has been visited. */

	int vSize = vertices.size();
	int numSubGraphs = 0;
	for(int i = 1; i < vSize; i++) {
		if(vertices[i]->visited == false) {
			numSubGraphs++;
			bft(vertices[i]->name ,vertices);
		}
	}

	if(numSubGraphs==0)
	{
		if(vSize > 0)
			numSubGraphs=1;
	}
	return numSubGraphs;
}



/* ==================Check Bipartite==============================
	Bipartite is when a graph's vertices can be split
 	into two groups, such that all vertices of one group
 	only have edges with vertices of the second group 

 	- When it is possible to color the vertices in two
 	  alternating colors, such that no two same-color
 	  vertices are ever adjacent.
 	- A graph is either bipartite or not.
 	- Various applications in parrellel computing, machine vision,
 	  (object recognition)

	Approach:
 	  1. Initiasize bipartite = true
 	  2. Set starting vertex as red or blue and mark it visited
 	  		-Doesn't really matter what vertex you start at.
 	  		-Function takes no parameters.

 	  // Function is like a modified BFT

 	  3. Initialize a queue
 	  4. Enqueue the starting vertex.
 	  5. loop until queuue is empty.
 	  		a. n = q.deQ
 	  		b. loop over n's adjacency list.
 	  			i. Check adjacent vertices
 	  					-if n->color=="red" && n->adj[x].v->color = "red"
 	  					OR
 	  					-if n->color=="blue" && n->adj[x].v->color = "blue"
 	  						return false

  				ii. if not visited
  					   -Color neghbors of n as opposite color
  						-mark as visited.

 	  6. Return true
  ===================================================================*/
bool bipartiteHelper(vertex *v, int vSize) {

	int adjSize;

	v->visited=true;
	v->color="RED";

	queue<vertex*> q;
	q.push(v);
	vertex *cur;

	while(!q.empty())
	{
		cur=q.front();
		adjSize = cur->adj.size();
		q.pop();

		for(int i = 0; i < adjSize;i++)
		{
    	   if(!cur->adj[i].v->visited) 
    	   {	
           cur->adj[i].v->visited = true;
           q.push(cur->adj[i].v);
           if(cur->color=="RED")
           	cur->adj[i].v->color = "BLUE";
           if(cur->color=="BLUE")
           	cur->adj[i].v->color = "RED";
         }

         if(cur->color==cur->adj[i].v->color)
         	return false;
         
			cout << endl;
			cout << "Current City = " << cur->name <<" Color: " << cur->color << endl;
			cout << "Adjacent City = " << cur->adj[i].v->name << " Color: " << cur->adj[i].v->color << endl;
			cout << "Queue Size = " << q.size();
			cout << endl;
			

		}
	}

	return true;
}

bool Graph::checkBipartite() {
	int vSize = vertices.size();
	bool bi;

	for(int i = 0; i < vSize; i++) {
		if(!vertices[i]->visited) {
			bi = bipartiteHelper(vertices[i], vSize);
			if(bi==false)
				return false;
		}
	}

	return true;
}
