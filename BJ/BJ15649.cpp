#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> used;
vector<int> answer;

void dfs(int dep) {
	if (dep == M) {
		for (int i = 0; i < M; i++)
		{
			cout << answer[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!used[i]) {
			used[i] = 1;
			answer[dep] = i + 1;
			dfs(dep + 1);
			used[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	used = vector<int>(N, 0);  // N 값을 받아 초기화
	answer = vector<int>(M, 0);
	dfs(0);
}