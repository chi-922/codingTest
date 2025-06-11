#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> answer;

void dfs(int dep, int start) {
	if (dep == M) {
		for (int i = 0; i < M; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < N; i++) {
		answer[dep] = i + 1;      // ���� i+1 ����
		dfs(dep + 1, i + 1);      // ���� �̱�� i+1���� ����
	}
}

int main() {
	cin >> N >> M;
	answer = vector<int>(M, 0);
	dfs(0, 0);
}