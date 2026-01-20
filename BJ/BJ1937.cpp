#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> bamboo;
vector<vector<int>> memo;
int n;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c, int bf) {
	if (r < 0 || r >= n || c < 0 || c >= n || bamboo[r][c] <= bf) {
		return 0;
	}
	if (memo[r][c] != -1) {
		return memo[r][c];
	}

	memo[r][c] = 0;
	for (int d = 0; d < 4; d++)
	{
		int nr = r + dr[d], nc = c + dc[d];
		memo[r][c] = max(memo[r][c], dfs(nr, nc, bamboo[r][c]) + 1);
	}

	return memo[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	bamboo.resize(n, vector<int>(n, 0));
	memo.resize(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> bamboo[i][j];
		}
	}

	int maxv = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = dfs(i, j, 0);
			maxv = max(maxv, temp);
		}
	}

	cout << maxv;
	return 0;
}