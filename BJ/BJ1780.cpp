#include <iostream>
#include <vector>

using namespace std;

int Mcnt = 0;
int Pcnt = 0;
int Zcnt = 0;
int n, temp;
vector<vector<int>> paper;

void conquer(int x, int y, int size) {
	bool isSame = true;

	// 모든 원소 같은지 확인
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			// 하나라도 틀린 순간 분할 시작
			if (paper[i][j] != paper[x][y]) {
				isSame = false;
				break;
			}
		}
		if (!isSame) {
			break;
		}
	}

	if (!isSame) {
		conquer(x, y, size / 3);
		conquer(x + (size / 3), y, size / 3);
		conquer(x + (size / 3 * 2), y, size / 3);
		conquer(x, y + (size / 3), size / 3);
		conquer(x + (size / 3), y + (size / 3), size / 3);
		conquer(x + (size / 3 * 2), y + (size / 3), size / 3);
		conquer(x, y + (size / 3 * 2), size / 3);
		conquer(x + (size / 3), y + (size / 3 * 2), size / 3);
		conquer(x + (size / 3 * 2), y + (size / 3 * 2), size / 3);
	}
	else {
		if (paper[x][y] == -1) {
			Mcnt += 1;
		} else if (paper[x][y] == 0) {
			Zcnt += 1;
		} else {
			Pcnt += 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	paper.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	conquer(0, 0, n);
	cout << Mcnt << '\n';
	cout << Zcnt << '\n';
	cout << Pcnt << '\n';
}