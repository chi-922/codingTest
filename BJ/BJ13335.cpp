#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, w, L;
	cin >> n >> w >> L;

	vector<int> truck(n);

	for (int i = 0; i < n; i++) cin >> truck[i];

	int answer = 1;
	queue<pair<int, int>> q;
	int weight = 0;
	int p = 0;

	while (true) {
		if (p < n && weight + truck[p] <= L)
		{
			q.push({ 1, truck[p] });
			weight += truck[p];
			p++;
		}

		int s = q.size();

		for (int i = 0; i < s; i++)
		{
			if (!q.empty())
			{
				int time = q.front().first;
				int load = q.front().second;
				q.pop();

				if (time != w)
					q.push({ time + 1, load });
				else
					weight -= load;

			}
		}

		answer++;

		if (p == n && q.empty())
			break;
	}

	cout << answer;
}