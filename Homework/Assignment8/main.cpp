#include "Graph.hpp"
#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[]) {
	
	Graph g;

	g.addVertex("Boulder");
	g.addVertex("Denver");
	g.addVertex("Cheyenne");
	g.addVertex("Fruita");
	g.addVertex("Moab");
	g.addVertex("Longmont");
	g.addVertex("London");
	g.addVertex("Paris");
	g.addVertex("Madrid");

	g.addEdge("Boulder", "Denver");
	g.addEdge("Boulder", "Cheyenne");
	g.addEdge("Fruita", "Denver");
	g.addEdge("Longmont", "Moab");
	g.addEdge("London", "Paris");
	g.addEdge("London", "Madrid");
	g.addEdge("Madrid", "Paris");

	g.displayEdges();
	cout << endl << "Num of Components = " << g.getConnectedComponents() << endl;
	cout << endl << "=============" << endl << "Graph is bipartite: ";
	cout << endl << g.checkBipartite() << endl;

}