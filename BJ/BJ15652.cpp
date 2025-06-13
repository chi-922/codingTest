#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> answer;

void dfs(int dep, int start) {
	if (dep == M) {
		for (int i = 0; i < M; i++)
		{
			cout << answer[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < N + 1; i++)
	{
		answer.push_back(i);
		dfs(dep + 1, i);
		answer.pop_back();
	}
}

int main() {
	cin >> N >> M;
	dfs(0, 1);
}