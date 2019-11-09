#include "Graph.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

	Graph g;

	g.addVertex("Aurora");
	g.addVertex("Bloomington");
	g.addVertex("Cheyenne");
	g.addVertex("Denver");
	g.addVertex("Fruita");

	g.addEdge("Aurora", "Bloomington", 5);
	g.addEdge("Aurora", "Cheyenne", 10);
	g.addEdge("Aurora", "Fruita", 30);
	g.addEdge("Bloomington", "Denver", 40);
	g.addEdge("Bloomington", "Fruita", 15);
	g.addEdge("Cheyenne", "Denver", 10);

	g.displayEdges();
	g.DijkstraAlgorithm("Aurora", "Fruita");

}
