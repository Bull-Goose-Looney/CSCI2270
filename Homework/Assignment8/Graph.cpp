#include "Graph.hpp"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph() {

}

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
		Vertex *nVert = new Vertex;
		v->name = name;
		vertices.push_back(nVert);
	}
}

void Graph::displayEdges() {
	for(int i=0;i<vertices.size();i++) {
		cout << vertices[i]->name << " --> ";
		for(int j=0;j<vertices[i]->adj.size();j++)
			cout << vertices[i]->adj[j]->name;
	}
}

void Graph::breadthFirstTraverse(string sourceVertex) {

}

int Graph::getConnecetedComponents() {

}

bool Graph::checkBipartite() {

}