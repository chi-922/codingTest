#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 1000000000

int n, m, u, v, w;
vector<tuple<int, int, int>> golmok;
vector<int> dist;
vector<int> path;

void bellmanFord() {
	dist[1] = 0;

	for (int i = 0; i < n; i++)
	{
		for (auto x : golmok) {
			int st = get<0>(x);
			int ed = get<1>(x);
			int w = get<2>(x);

			int cost = dist[st] + w;
			if (dist[st] == INF) continue;

			if (cost < dist[ed]) {
				// ����, ��� ��� ���� �Դ��� ������ �����
				dist[ed] = cost;
				path[ed] = st;  // ed�ε����� st���� �Դ�

				if (i == n - 1) {
					dist[ed] = -INF;
				}
			}
		}
	}

	// �� ���Ҵµ� n���� ���� ���ϸ� -1
	if (dist[n] == INF || dist[n] == -INF) {
		cout << -1;
		return;
	}

	// path ���
	vector<int> result;
	int cur = n;
	while (cur != 0) {
		result.push_back(cur);
		cur = path[cur];
	}

	// ����� �����̹Ƿ� ����� ���
	for (auto it = result.rbegin(); it != result.rend(); ++it) {
		cout << *it << ' ';
	}
}

int main() {
	cin >> n >> m;
	dist.resize(n + 1, INF);
	path.resize(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		golmok.push_back({ u, v, -w });
	}

	bellmanFord();
}