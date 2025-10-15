#include <iostream>

using namespace std;

int n, m;
int parents[501];
int caseNum = 1;

int findParent(int a) {
	if (a == parents[a]) return a;
	int p = findParent(parents[a]);
	parents[a] = p;

	return p;
}

void setUnion(int& a, int& b) {
	int pA = findParent(a);
	int pB = findParent(b);

	if (pA > pB) parents[pA] = pB;
	else if (pA < pB) parents[pB] = pA;
	else {
		// 사이클인 경우는 0이라 하자
		parents[pA] = 0;
		parents[pB] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while(true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			parents[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int s, e;
			cin >> s >> e;
			setUnion(s, e);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (parents[i] == i)ans++;
		}

		if (ans == 0) {
			cout << "Case " << caseNum++ << ": " << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "Case " << caseNum++ << ": " << "There is one tree.\n";
		}
		else {
			cout << "Case " << caseNum++ << ": " << "A forest of " << ans << " trees.\n";
		}
	}
}