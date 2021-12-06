#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

class Graph
{
    int numVertices;
    list<int>* adjLists;

    int start;
    int dc;

    vector<int> flag; // (0, 1, 2)
    vector<int> cycles;
    int cycles_counter = 0;

public:
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
                                adjLists[src].push_back(atoi(&buff_size[j]));
                            }
                            j++;
                        }
                    }
                }
            }
            flag.resize(numVertices);
            filein.close();
        }
        else {
            cout << "\n File error.";
        }
    }

    friend ostream& operator << (ostream& os, Graph& graphy) {
        os << "\n";
        for (int q = 0; q < graphy.numVertices; q++) {
            os << " " << q << " ->";
            for (auto v : graphy.adjLists[q])
                os << " " << v;
            os << "\n";
        }
        return os;
    }

    void retrieve(int curr) {
        for (auto u : adjLists[curr]) {
            if (u == start) {
                cout << u;
                return;
            }
        }
        if (flag[curr] == 1) {
            cout << curr;
            retrieve(curr);
            return;
        }
    }

    void find_cycles(int curr) {
        cycles.push_back(curr);
        cout << "\n Entered " << curr;
        flag[curr] = 1;
        for (auto u : adjLists[curr]) {
            if (flag[u] == 0) {
                find_cycles(u);
            }
            if (flag[u] == 1) {
                cout << "\n  " << ++cycles_counter << ". ";
                for (int i : cycles)
                    cout << i;

                cout << u;
                if (u != start) {
                    retrieve(u);
                }
            }
            for (int i : cycles)
                i = 0;

            if (curr == start) {
                cout << "\n Clearing flags " << curr;
                cycles.clear();
                cycles.push_back(start);

                for (int i = 0; i < flag.size(); i++)
                    flag[i] = 0;
                flag[0] = 1;
            }
        }
        cout << "\n Blacklisted " << curr;
        flag[curr] = 3;
    }

    int get_start() {
        return start;
    }
};

#endif // !