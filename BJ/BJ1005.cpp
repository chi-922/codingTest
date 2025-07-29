#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while (test--) {
        int n, k;
        cin >> n >> k;

        vector<int> buildTime(n + 1);
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> buildTime[i];
        }

        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].emplace_back(to);
            indegree[to]++;
        }

        int target;
        cin >> target;

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = buildTime[i];
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : graph[curr]) {
                // dp[next]: 현재까지 계산된 최대 시간
                // dp[curr] + build_time[next]: 현재 건물을 거쳐서 가는 경우의 시간
                dp[next] = max(dp[next], dp[curr] + buildTime[next]);
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[target] << '\n';
    }

    return 0;
}