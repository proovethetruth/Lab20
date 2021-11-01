#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Graph
{
    int numVertices;
    list<int>* adjLists;
    int start;
    int dc;

public:
    void addEdge(int src, int dest)
    {
        adjLists[src].push_front(dest);
    }
    void start_and_dc(string file) {
        ifstream filein(file);
        char tmp[3] = "0";

        if (filein) {
            for (int j = 0; j < 3; j++) {
                char buff[30] = "0";
                filein.getline(buff, 30);
                int count = 0;
                for (size_t i = 0; i < 30; i++) {
                    if (buff[i] >= '0' && buff[i] <= '9')
                        tmp[count++] = buff[i];
                }
                if (j == 0)
                    dc = atoi(tmp);
                if (j == 1)
                    start = atoi(tmp);
                if (j == 2)
                    numVertices = atoi(tmp);
            }
            adjLists = new list<int>[numVertices];

            int src = 0;
            for (int i = 0; i < numVertices; i++) {
                char buff_size[30] = "0";
                filein.getline(buff_size, 30);
                for (int j = 0; j < 30; j++) {
                    if (buff_size[j] >= '0' && buff_size[j] <= '9') {
                        src = atoi(&buff_size[j]);
                        j++;
                        while (j < 30) {
                            if ((buff_size[j] != ' ') && buff_size[j] >= '0' && buff_size[j] <= '9') {
                                adjLists[src].push_front(atoi(&buff_size[j]));
                            }
                            j++;
                        }
                    }
                }
            }
            filein.close();
            for (auto v : *adjLists)
                std::cout << v << "\n";
        }
        else {
            cout << "\n File error.";
        }
    }
};

#endif // !