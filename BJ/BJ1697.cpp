#include <iostream>
#include <queue>

using namespace std;

int n, k, temp;
int visited[100001] = { 0, };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == k) {
			cout << cnt;
			return;
		}

		if (now + 1 <= 100000 && !visited[now + 1]) {
			q.push({ now + 1, cnt + 1 });
			visited[now + 1] = 1;
		}

		if (now * 2 <= 100000 && !visited[now * 2]) {
			q.push({ now * 2, cnt + 1 });
			visited[now * 2] = 1;
		}

		if (now - 1 >= 0 && !visited[now - 1]) {
			q.push({ now - 1, cnt + 1 });
			visited[now - 1] = 1;
		}
	}
}


int main() {
	cin >> n >> k;

	bfs();
}