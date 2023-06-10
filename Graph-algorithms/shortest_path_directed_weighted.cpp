#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Pair of (distance, node)

void shortestPath(const vector<vector<pii>>& graph, int start, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, numeric_limits<int>::max());
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) {
            continue;
        }

        for (const auto& neighbor : graph[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif
    
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        graph[x].push_back({y, r});
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        vector<int> dist;
        shortestPath(graph, a, dist);

        if (dist[b] == numeric_limits<int>::max()) {
            cout << -1 << endl;
        } else {
            cout << dist[b] << endl;
        }
    }

    return 0;
}
