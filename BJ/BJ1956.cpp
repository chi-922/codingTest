#include <iostream>
#include <vector>

#define INF 1000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int v, e, a, b, c;
	cin >> v >> e;

	vector<vector<int>> town(v + 1, vector<int>(v + 1, INF));

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		town[a][b] = min(town[a][b], c);
	}

	for (int i = 1; i < v + 1; i++)
	{
		town[i][i] = 0;
	}

	for (int k = 1; k < v + 1; k++)
	{
		for (int n = 1; n < v + 1; n++)
		{
			for (int m = 1; m < v + 1; m++)
			{
				town[n][m] = min(town[n][m], town[n][k] + town[k][m]);
			}
		}
	}

	int minPath = INF;
	for (int i = 1; i < v ; i++)
	{
		for (int j = i + 1; j < v + 1; j++)
		{
			minPath = min(minPath, town[i][j] + town[j][i]);
		}
	}

	if (minPath == INF) {
		cout << -1;
	}
	else {
		cout << minPath;
	}
}