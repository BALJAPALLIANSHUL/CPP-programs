#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // pair of node and distance

vector<int> dijkstra(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    distance[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) {
            continue;
        }

        for (const auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            int new_dist = dist + weight;

            if (new_dist < distance[neighbor]) {
                distance[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    // Build the graph
    for (int i = 0; i < m; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        graph[x - 1].push_back({y - 1, r});
    }

    int q;
    cin >> q;

    // Perform queries
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        vector<int> distance = dijkstra(graph, a - 1);
        if (distance[b - 1] == numeric_limits<int>::max()) {
            cout << -1 << endl;
        } else {
            cout << distance[b - 1] << endl;
        }
    }

    return 0;
}
