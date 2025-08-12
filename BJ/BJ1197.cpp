#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> visited;

int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[start] = 1;

    // 시작점의 모든 간선을 PQ에 삽입
    for (auto& edge : tree[start]) {
        pq.push({ edge.second, edge.first });
    }

    int ans = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node]) {
            visited[node] = 1;
            ans += weight;

            for (auto& x : tree[node]) {
                if (!visited[x.first]) {
                    pq.push({ x.second, x.first });
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    tree.assign(v + 1, {});
    visited.assign(v + 1, 0);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b, c });
        tree[b].push_back({ a, c });
    }

    cout << prim(1);
}
