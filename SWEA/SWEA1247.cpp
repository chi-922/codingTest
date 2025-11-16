#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int INF = 10000000;

int answer = INF;

void dfs(vector<pair<int, int>>& coordinate, vector<int>& visited, int now, int distance, int depth, int& n) {
	if (depth == n)
	{
		int dis = distance + abs(coordinate[now].first - coordinate[1].first) + abs(coordinate[now].second - coordinate[1].second);
		answer = min(answer, dis);
		return;
	}

	if (distance >= answer) return;

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		int diff = abs(coordinate[now].first - coordinate[i + 2].first) + abs(coordinate[now].second - coordinate[i + 2].second);
		dfs(coordinate, visited, i + 2, distance + diff, depth + 1, n);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	vector<pair<int, int>> coordinate;
	vector<int> visited;

	for (int tc = 1; tc <= T; tc++)
	{
		answer = INF;
		
		int num;
		cin >> num;

		coordinate.assign(num + 2, {});
		visited.assign(num, 0);

		for (int i = 0; i < num + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			coordinate[i] = { x, y };
		}

		dfs(coordinate, visited, 0, 0, 0, num);

		cout << '#' << tc << ' ' << answer << '\n';
	}
}