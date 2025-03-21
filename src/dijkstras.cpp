#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    if (n==0) return {};
    vector<int> distances(n , INF);
    vector<bool> visited(n, false);
    distances[source] = 0;
    previous.resize(n, -1);
    previous[source] = UNDEFINED;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge: G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> shortest_path;
    while (destination != -1) {
        shortest_path.push_back(destination);
        destination = previous[destination];
    }
    int v_left = 0;
    int v_right = shortest_path.size() - 1;
    while (v_left < v_right) {
        swap(shortest_path[v_left], shortest_path[v_right]);
        ++v_left;
        --v_right;
    }
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for (auto p: v) {
        cout << p << " ";
    }
    cout << endl << "Total cost is " << total << endl;
}