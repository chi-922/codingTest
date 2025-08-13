#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<pair<float, float>> galaxy;
vector<int> visited;

float distance(const pair<float, float>& p1, const pair<float, float>& p2) {
	float dx = p1.first - p2.first;
	float dy = p1.second - p2.second;
	return sqrtf(dx * dx + dy * dy);
}

float prim(int gp) {
	priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
	pq.push({ 0, gp });   // 가중치, 별 idx
	visited[gp] = 1;

	int count = 0; // 간선 수 n-1
	float dis = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == gp) continue;
		pq.push({ distance(galaxy[i], galaxy[gp]), i });
	}

	while (count < n && !pq.empty()) {
		float weight = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (visited[idx]) continue;

		visited[idx] = 1;
		dis += weight;
		count++;

		for (int i = 0; i < n; i++)
		{
			if (i == idx) continue;
			if (visited[i]) continue;
			pq.push({ distance(galaxy[idx], galaxy[i]), i});
		}
	}

	return dis;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	galaxy.resize(n);
	visited.resize(n, 0);


	for (int i = 0; i < n; i++)
	{
		float x, y;
		cin >> x >> y;
		galaxy[i] = { x, y };
	}

	cout << fixed;
	cout.precision(2);
	cout << prim(0);
}