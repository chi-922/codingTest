#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e18
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
vector<long long> dist;

void bellmanFord(int start) {
    dist.assign(n + 1, INF);
    dist[start] = 0;

    // 모든 간선을 기준으로 탐색
    for (int i = 1; i <= n; i++) {
        for (auto [s, e, d] : edges) {
            if (dist[s] == INF) continue;

            long long next_dist = dist[s] + d;

            if (next_dist < dist[e]) {
                dist[e] = next_dist;
                if (i == n) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    edges.resize(m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = { a, b, c };
    }

    bellmanFord(1);
}
