#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<pair<int, int>>> tree;
bool visited[100001];
int maxDist = 0;
int farNode = 0;

void bfs(int start) {
    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    q.push({ start, 0 });
    vis[start] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist > maxDist) {
            maxDist = dist;
            farNode = cur;
        }

        for (auto& [next, cost] : tree[cur]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push({ next, dist + cost });
            }
        }
    }
}

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
    }

    for (auto& [next, cost] : tree[node]) {
        if (!visited[next]) {
            dfs(next, dist + cost);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.resize(n + 1);

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        while (true) {
            int to, cost;
            cin >> to;
            if (to == -1) break;
            cin >> cost;
            tree[node].push_back({ to, cost });
        }
    }

    // BFS로 가장 먼 노드 찾기
    maxDist = 0;
    bfs(1);

    // DFS로 지름 구하기
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farNode, 0);

    cout << maxDist << '\n';
    return 0;
}