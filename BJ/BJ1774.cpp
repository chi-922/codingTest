#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

vector<int> parents;
vector<pair<int, int>> gods;
vector<tuple<double, int, int>> edge ;

double distance(const pair<int, int>& p1, const pair<int, int>& p2) {
	double dx = p1.first - p2.first;
	double dy = p1.second - p2.second;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

int findParent(int idx) {;
	if (parents[idx] != idx) {
		parents[idx] = findParent(parents[idx]);  // parent즉시반영
	}
	return parents[idx];
}

void unionSet(int x, int y) {
	int xPar = findParent(x);
	int yPar = findParent(y);

	if (xPar == yPar) return;

	if (xPar < yPar) {
		parents[yPar] = xPar;
	}
	else {
		parents[xPar] = yPar;
	}
	// return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	parents.resize(n + 1);
	gods.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
	{
		parents[i] = i;
	}
	for (int i = 1; i < n + 1; i++)
	{
		int x, y;
		cin >> x >> y;
		gods[i] = { x, y };
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		unionSet(a, b);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n + 1; j++)
		{
			edge.push_back({ distance(gods[i], gods[j]), i, j });
		}
	}

	sort(edge.begin(), edge.end());

	double ans = 0;
	int cnt = 0;
	for (auto x : edge)
	{
		double dist = get<0>(x); // 첫 번째 요소 (double)
		int a = get<1>(x);      // 두 번째 요소 (int)
		int b = get<2>(x);      // 세 번째 요소 (int)

		if (findParent(a) != findParent(b)) {
			cnt++;
			unionSet(a, b);
			ans += dist;

			if (cnt == n - 1) break;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;
}