#include <iostream>
#include <vector>

using namespace std;

int parent[1000002];

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void unionSet(int x, int y) {
	int xPar = find(x);
	int yPar = find(y);

	if (xPar == yPar) {
		return;
	}
	
	if (xPar < yPar) {
		parent[yPar] = xPar;
	}
	else {
		parent[xPar] = yPar;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + 1; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int action, a, b;
		cin >> action >> a >> b;

		if (action == 0) {
			unionSet(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}