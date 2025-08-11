#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> city;
vector<int> visited;
int t;

int prim() {
    int ans = 0;
    queue<int> q;
    visited[1] = 1; // 1번 나라부터 시작
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int x : city[cur]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        city.assign(n + 1, {});
        visited.assign(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            city[u].push_back(v);
            city[v].push_back(u);
        }

        cout << prim() << '\n';
    }
}
