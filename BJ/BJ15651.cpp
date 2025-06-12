#include <iostream>
#include <vector>

using namespace std;

int N, M;
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

	for (int i = 1; i < N + 1; i++)
	{
		answer.push_back(i);
		dfs(dep + 1);
		answer.pop_back();
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
}