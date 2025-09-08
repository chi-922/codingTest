#include <iostream>
#include <vector>

using namespace std;
int N;
int ans = 0;
vector<vector<int>> board;
int dirr[4] = { 0, 1, 0, -1 };
int dirc[4] = { -1, 0, 1, 0 };

int xdx[4][10] = { {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, { -1, -1, 0, 0, 1, 1, 0, 0, 2, 1}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {1, 1, 0, 0, -1, -1, 0, 0, -2, -1} };
int ydy[4][10] = {{ 1,  1,  0,  0, -1, -1,  0,  0, -2, -1}, {-1,  1, -1,  1, -1,  1, -2,  2,  0,  0}, {-1, -1,  0,  0,  1,  1,  0,  0,  2,  1}, { 1, -1,  1, -1,  1, -1,  2, -2,  0,  0} };
int percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

void tornado(int dir, int yr, int yc) {
	int sand = board[yr][yc];
	int temp = sand;
	for (int i = 0; i < 9; i++)
	{
		int nr = yr + xdx[dir][i];
		int nc = yc + ydy[dir][i];
		int per = percent[i];
		int plus = (temp * per) / 100;

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += plus;
		else board[nr][nc] += plus;

		sand -= plus;
	}

	// 마지막 알파 방향
	int nr = yr + xdx[dir][9];
	int nc = yc + ydy[dir][9];

	if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += sand;
	else board[nr][nc] += sand;
	board[yr][yc] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	board.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int r = N / 2, c = N / 2;
	int dir = 0;

	// len=1..N-1: 각각 두 구간씩
	for (int len = 1; len < N; ++len) {
		for (int t = 0; t < 2; ++t) {
			for (int s = 0; s < len; ++s) {
				r += dirr[dir];
				c += dirc[dir];
				tornado(dir, r, c);               // 이동한 칸에서 퍼뜨리기
				if (r == 0 && c == 0) {           // (0,0)에서 마무리
					cout << ans;
					return 0;
				}
			}
			dir = (dir + 1) % 4;                  // 매 구간마다 회전
		}
	}

	// 마지막 구간: len = N-1 한 번
	for (int s = 0; s < N - 1; ++s) {
		r += dirr[dir];
		c += dirc[dir];
		tornado(dir, r, c);
		if (r == 0 && c == 0) break;
	}

	cout << ans;

}