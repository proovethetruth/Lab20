
#include <iostream>
#include "graph.h"

// ��������������� ���� ����� � �������� ������� ���������.
// � ����� �������� �������, � ������� ���������� ����� � ����� ����� dc.
// �������� ��� �����, ����� ������� ������ dc.


int main() {
	Graph graph1;
	graph1.start_and_dc("Input1.txt");
	std::cout << graph1 << "\n Cycles:";

	graph1.find_cycles(graph1.get_start());
}