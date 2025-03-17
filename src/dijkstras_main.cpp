#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("/home/pthurgam/ICS46/HW9/src/medium.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int i = 0; i < G.numVertices; ++i) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }
    return 0;

}