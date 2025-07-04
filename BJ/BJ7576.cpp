#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, temp;
int day = 0;
vector<vector<int>> tomato;
queue<pair<int, int>> tm;
pair<int, int> direc[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };


void bfs() {
	queue<pair<int, int>> q;
	while (!tm.empty() || !q.empty()) {
		if (tm.empty())
		{
			while (!q.empty()) {
				pair<int, int> x = q.front();
				q.pop();
				tm.push(x);
			}
			day++;
		}

		pair<int, int> now = tm.front();
		tm.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = now.first + direc[i].first;
			int nc = now.second + direc[i].second;

			if (0 <= nr && nr < m && 0 <= nc && nc < n && tomato[nr][nc] == 0)
			{
				tomato[nr][nc] = 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	tomato.resize(m, vector<int>(n, 0));
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				tm.push(make_pair(i, j));
			}
		}
	}

	if (tm.size() == n * m) {
		cout << "0";
		return 0;
	}
	else {
		bfs();

		bool flag = true;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tomato[i][j] == 0) {
					flag = false;
					break;
				}
			}
			
			if (!flag) break;
		}

		if (flag) {
			cout << day;
		}
		else {
			cout << "-1";
		}
	}
}