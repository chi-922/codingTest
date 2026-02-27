#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N, L;
vector<pair<int, int>> indeg;
int maxv = 0;

void dfs(int st, int com, int satisfy) {
	if (com > L) return;

	// 현재 상태는 항상 후보
	maxv = max(maxv, satisfy);

	// 끝까지 봤으면 종료
	if (st == N) return;

	for (int i = st; i < N; i++) {
		dfs(i + 1, com + indeg[i].second, satisfy + indeg[i].first);
	}
}

int main() {
	(void)freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> N >> L;
		indeg.clear();
		maxv = 0;
		
		for (int i = 0; i < N; i++) {
			int score, cal;
			cin >> score >> cal;
			indeg.push_back({ score, cal });
		}

		dfs(0, 0, 0);
		cout << "#" << t << ' ' << maxv << endl;
	}

	return 0;
}