#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visited[100001] = { 0, };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == k) {
			cout << cnt;
			return;
		}

		if (now * 2 <= 100000) {
			if (!visited[now * 2] || visited[now * 2] > cnt) {
				visited[now * 2] = cnt;
				q.push({ now * 2, cnt });
			}
		}

		if (now - 1 >= 0) {
			if (!visited[now - 1] || visited[now - 1] > cnt + 1) {
				visited[now - 1] = cnt + 1;
				q.push({ now - 1, cnt + 1 });
			}
		}

		if (now + 1 <= 100000) {
			if (!visited[now + 1] || visited[now + 1] > cnt + 1) {
				visited[now + 1] = cnt + 1;
				q.push({ now + 1, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> k;

	bfs();
}