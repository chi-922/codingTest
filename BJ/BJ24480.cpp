#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<int> graph[100001];
int visited[100001] = { 0, };
int order[100001] = { 0, };
int cnt = 1;
int u, v;

void dfs(int& r) {
	stack<int> st;
	st.push(r);

	while (!st.empty())
	{
		int now = st.top();
		st.pop();
		
		if (!visited[now]) {
			visited[now] = 1;
			order[now] = cnt++;

			for (int x : graph[now])
			{
				if (!visited[x]) {
					st.push(x);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n ; i++)
	{
		cout << order[i] << '\n';
	}
}