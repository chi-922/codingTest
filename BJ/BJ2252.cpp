#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<int> num_entry(v + 1, 0);
    vector<vector<int>> adj_list(v + 1);

    // 간선 입력
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        num_entry[b]++;
    }

    queue<int> q;
    vector<int> result;

    // 진입차수 0인 노드 큐에 추가
    for (int i = 1; i <= v; i++) {
        if (num_entry[i] == 0) {
            q.push(i);
        }
    }

    // 위상정렬
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int next : adj_list[now]) {
            if (--num_entry[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
