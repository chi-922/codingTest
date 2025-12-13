#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	
	int go[101] = { 0, };
	for (int i = 0; i < n + m; i++) {
		int u, v;
		cin >> u >> v;
		go[u] = v;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> game;   // 횟수, 현재위치
	int visited[101] = { 0, };

	game.push({ 0, 1 });
	visited[1] = 1;

	int answer = 0;

	while (!game.empty()) {
		int cnt = game.top().first, now = game.top().second;
		game.pop();
		
		for (int i = 1; i < 7; i++)
		{
			if (now + i > 100) continue;
			int next = now + i;
			while (go[next]) next = go[next];
			if (visited[next]) continue;

			if (next == 100) {
				answer = cnt + 1;
				break;
			}

			game.push({ cnt + 1, next });
			visited[next] = 1;
		}

		if (answer) break;
	}

	cout << answer;

	return 0;
}