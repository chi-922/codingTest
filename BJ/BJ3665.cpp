#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, N, M;
int indegree[501];
bool adj[501][501]; // 인접 행렬
int lastYear[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;

        memset(indegree, 0, sizeof(indegree));
        memset(adj, false, sizeof(adj));

        for (int i = 1; i <= N; i++) {
            cin >> lastYear[i];
        }

        // 작년 순위로 방향 그래프 구성
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                adj[lastYear[i]][lastYear[j]] = true;
                indegree[lastYear[j]]++;
            }
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            // 간선 방향 뒤집기
            if (adj[a][b]) {
                adj[a][b] = false;
                adj[b][a] = true;
                indegree[b]--;
                indegree[a]++;
            }
            else {
                adj[b][a] = false;
                adj[a][b] = true;
                indegree[a]--;
                indegree[b]++;
            }
        }

        // 위상 정렬 시작
        queue<int> q;
        vector<int> result;
        bool ambiguous = false;
        bool impossible = false;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        for (int i = 0; i < N; i++) {
            if (q.empty()) {
                impossible = true;
                break;
            }

            if (q.size() > 1) {
                ambiguous = true;
                break;
            }

            int cur = q.front(); q.pop();
            result.push_back(cur);

            for (int next = 1; next <= N; next++) {
                if (adj[cur][next]) {
                    if (--indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }

        if (impossible) {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambiguous) {
            cout << "?\n";
        }
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
