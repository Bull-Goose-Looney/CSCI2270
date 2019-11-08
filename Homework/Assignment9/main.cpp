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

	g.addEdge("Boulder", "Denver", 5);
	g.addEdge("Boulder", "Cheyenne", 5);
	g.addEdge("Fruita", "Denver", 5);
	g.addEdge("Longmont", "Moab", 5);
	g.addEdge("London", "Paris", 5);
	g.addEdge("London", "Madrid", 5);
	g.addEdge("Madrid", "Paris", 5);

	g.displayEdges();
	g.depthFirstTraversal("Boulder");

}