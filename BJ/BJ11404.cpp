#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int n, m, a, b, c;
vector<vector<int>> bus;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	bus.resize(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}

	for (int i = 1; i < n + 1; i++)
	{
		bus[i][i] = 0;
	}

	// k : 경유하려는 정점
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (bus[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << bus[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}