#include "Graph.hpp"
#include <queue>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Connects v1 and v2 to eachother.
void Graph::addEdge(string v1, string v2, int weight) {
	//Loop through Vertices (nodes);
	int vSize = vertices.size();

	for(int i = 0; i < vSize; i++) {
		if(vertices[i]->name == v1) { // Find v1
			for(int j = 0; j < vSize; j++) { // Find v2 if v1 is found
				if(vertices[j]->name == v2 && i != j) {
					adjVertex ad; // New Vertex Pointer;
					ad.v = vertices[j]; // Vertex pointer = v2
					ad.weight = weight;
					vertices[i]->adj.push_back(ad); // Add v2 to V1's connections
					adjVertex ad2; // New Vertex Pointer(v1)
					ad2.v = vertices[i]; // Vertex = v1
					ad2.weight = weight;
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
	cout << endl;
}

void dftHelper(vertex *v) {
	v->visited = true;
	int adjSize = v->adj.size();

	for(int i = 0; i < adjSize; i++) {
		if(v->adj[i].v->visited==false)
		{
			cout << v->adj[i].v->name << " --> ";
			dftHelper(v->adj[i].v);
		}
	}
}

void Graph::depthFirstTraversal(string sourceVertex) {
	int vSize = vertices.size();
	for(int i = 0; i < vSize; i++){
 		if(vertices[i]-> name == sourceVertex) {
 			cout << vertices[i]->name << " --> ";
 			dftHelper(vertices[i]);
 		}
	}
		cout << "Done";
}


vertex* search(string name, vector<vertex*>vertices) {
	int vSize = vertices.size();
	vertex *rVert = NULL;

	for(int i = 0; i < vSize; i++) {
		if(vertices[i]->name == name)
			rVert = vertices[i];
	}

	return rVert;
}

vertex* Graph::DijkstraAlgorithm(string start, string end) {
	int minDist = 1000;
	int SLsize;
	int adjSize;
	int dist;

	vertex *vStart = search(start, vertices);
	vertex *vEnd = search(end, vertices);
	vertex *solvedV = NULL;
	vertex *s = NULL;

	// If either vertex isnt found
	if(vStart==NULL||vEnd==NULL)
		return NULL;

	vector<vertex*>solvedList; //solved list
	solvedList.push_back(vStart); // Starting vertex solved as 0;
	vStart->distance = 0; // 0 away from itself
	vStart->visited = true;

	while(!vEnd->visited) {
		minDist = 1000;
		SLsize = solvedList.size();
		for(int i = 0; i < SLsize; i++) { // Loop through entire solvedL
			s = solvedList[i]; // Store solved in temp look at its adjlist
			adjSize = s->adj.size();
			for(int x = 0; x < adjSize; x++) { // Loop through s's adjlist
				if(!s->adj[x].v->visited) { // only check visited.d
				 	dist = s->distance + s->adj[x].weight; // Distance chk
					if(dist < minDist) {
						solvedV = s->adj[x].v; // This is next solved vertex
						minDist = dist; // Set new minDist
						s->adj[x].v->pred = s; // Set 
					}
				}
			}
		}
		solvedV->distance = minDist;
		solvedV->visited = true;
		solvedList.push_back(solvedV);
	} // While end

	return vEnd;
}


void Graph::shortestpath(string start, string end) {
	vertex *v = search(end, vertices);
	stack<string>names;


	while(v!=NULL) {
		names.push(v->name);
		v = v->pred;
	}

	while(!names.empty()) {
		cout << names.top() << " ";
		names.pop();
	}
}
