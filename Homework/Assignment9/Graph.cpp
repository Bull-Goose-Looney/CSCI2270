#include "Graph.hpp"
#include <queue>
#include <iostream>
#include <string>
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


	/* 			     NOTES: Dijkstra's Algo
	===================================================
	- BFS will not work with weights
	- Flight routing number of layovers 
	  (BFS) vs. Total Distance (Dijkstras)
	- Goal is to find path with lowest weight from a-b.
	
											SUDO:
	--------------------------------------------
	1. Start at A, mark as "solved" or "visited"
		 and add to solved list.
	2. Set Distance of A to zero since it takes
		 zero distance to get from a to a.
	3. Traverse the entire solved list
			a. Scan A's adj list and find unsolved
				 vertex that is CLOSEST to a.
			b. Mark closest vertex as solved and add
				 to solved list.
	4. Traverse the entire solved list again. 
			a. Scan A's adj list and find un-solved ver-
			   tex nearest to A.
			b. Scan B's adj list and find un-solved ver-
				 tex nearest A.
			c. Mark the closest vertex (from a to b) as solved.
	5. Traverse entire solved list again again
			a. Scan A's adj list, closest == e(5)
			b. Scan B's adj list, closest == none
			c. Scan C's adj list, closest == D(3)
			d. min(a,b,c) = d(3).
			e. Note that only d is marked as solved


  - Repeat steps until all paths are traversed and 
    choose the shortest ones. */

vertex* DijkstraAlgorithm(string start, string end) {

}

