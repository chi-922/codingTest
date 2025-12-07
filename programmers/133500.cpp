// 등대

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> visited;

void dfs(int u) {
    visited[u] = 1;
    dp[u][1] = 1; // u가 켜진 경우

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);

            dp[u][1] += min(dp[v][0], dp[v][1]);
            dp[u][0] += dp[v][1];
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    adj.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    visited.assign(n + 1, 0);

    for (auto &e : lighthouse) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    dfs(1);
    return min(dp[1][0], dp[1][1]);
}
