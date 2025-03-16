#include "dijkstras.cpp"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({source, 0});
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
                minHeap.push({v, distances[v]});
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
    left = 0;
    right = shortest_path.size() - 1;
    while (left < right) {
        swap(v[left], v[right]);
        ++left;
        --right;
    }
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    
}