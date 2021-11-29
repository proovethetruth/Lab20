
#include <iostream>
#include "graph.h"

// Ориентированный граф задан и хранится списком смежности.
// В файле задается вершина, с которой начинается обход и длина цикла dc.
// Выписать все циклы, длина которых меньше dc.


int main() {
	Graph graph1;
	graph1.start_and_dc("Input1.txt");
	std::cout << graph1 << "\n Cycles:";

	graph1.find_cycles(graph1.get_start());
}