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