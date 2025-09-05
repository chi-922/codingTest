#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct fireball {
	int m, s, d;
	bool isNew;
};

int N, M, K;
vector<vector<queue<fireball>>> board;
vector<vector<int>> numOfFireball;

int dirr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dirc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int wrap(int x) {
	return ((x % N) + N) % N;
}

void moving () {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size())
			{
				int turn = board[i][j].size();
				while(turn--)
				{
					fireball nowball = board[i][j].front();
					board[i][j].pop();
					if (!nowball.isNew)
					{
						int newr = wrap(i + dirr[nowball.d] * nowball.s);
						int newc = wrap(j + dirc[nowball.d] * nowball.s);
						nowball.isNew = true;
						board[newr][newc].push(nowball);
					}
					else {
						board[i][j].push(nowball);
					}
				}
			}
		}
	}
}

void magic() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size())
			{
				int num = board[i][j].size();
				if (num >= 2)
				{
					int summ = 0, sums = 0;
					int iseven = 0, isodd = 0;
					while (!board[i][j].empty())
					{
						fireball nowball = board[i][j].front();
						board[i][j].pop();
						
						summ += nowball.m;
						sums += nowball.s;
						if (nowball.d % 2 == 0)
						{
							iseven = 1;
						}
						else {
							isodd = 1;
						}
					}
					
					if (summ / 5) {
						int newm = summ / 5;
						int news = sums / num;
						if (iseven + isodd == 1)
						{
							board[i][j].push({ newm, news, 0, false });
							board[i][j].push({ newm, news, 2, false });
							board[i][j].push({ newm, news, 4, false });
							board[i][j].push({ newm, news, 6, false });
						}
						else {
							board[i][j].push({ newm, news, 1, false });
							board[i][j].push({ newm, news, 3, false });
							board[i][j].push({ newm, news, 5, false });
							board[i][j].push({ newm, news, 7, false });
						}
					}
				}
				else {
					fireball nowball = board[i][j].front();
					board[i][j].pop();
					nowball.isNew = false;
					board[i][j].push(nowball);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	board.resize(N, vector<queue<fireball>>(N));

	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;

		board[r - 1][c - 1].push({ m, s, d, false });
	}

	while (K--)
	{
		moving();
		magic();
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size())
			{
				while (!board[i][j].empty())
				{
					fireball nowball = board[i][j].front();
					board[i][j].pop();
					ans += nowball.m;
				}
			}
		}
	}

	cout << ans;
}