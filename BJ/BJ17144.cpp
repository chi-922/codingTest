#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dust;
int R, C, T;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void diffusion() {
	vector<vector<int>> result(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (dust[i][j] > 0)
			{
				int dir = 0;
				int dividedDust = dust[i][j] / 5;
				for (int d = 0; d < 4; d++)
				{
					int nr = i + dr[d], nc = j + dc[d];
					if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
					if (dust[nr][nc] == -1) continue;
					dir++;
					result[nr][nc] += dividedDust;
				}
				result[i][j] -= dir * dividedDust;
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			dust[i][j] += result[i][j];
		}
	}
}

void clean(vector<int>& machine) {
	int clockR[4] = { 0, 1, 0, -1 };
	int clockC[4] = { 1, 0, -1, 0 };
	int antiR[4] = { 0, -1, 0, 1 };
	int antiC[4] = { 1, 0, -1, 0 };

	int temp = 0; int delivery = 0;
	int cr = machine[0]; int cc = 1;
	int d = 0;
	// 반시계 부터
	while (dust[cr][cc] != -1 && d < 4)
	{
		int nr = cr + antiR[d], nc = cc + antiC[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C)
		{
			d++;
			continue;
		}
		temp = dust[cr][cc];
		dust[cr][cc] = delivery;
		delivery = temp;
		cr = nr; cc = nc;
	}

	cr = machine[1]; cc = 1;
	temp = 0; delivery = 0;
	d = 0;
	// 시계 부터
	while (dust[cr][cc] != -1 && d < 4)
	{
		int nr = cr + clockR[d], nc = cc + clockC[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C)
		{
			d++;
			continue;
		}
		temp = dust[cr][cc];
		dust[cr][cc] = delivery;
		delivery = temp;
		cr = nr; cc = nc;
	}
}

int main() {
	cin >> R >> C >> T;
	dust.resize(R, vector<int>(C, 0));

	vector<int> machine;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> dust[i][j];
			if (dust[i][j] == -1) machine.push_back(i);
		}
	}

	while (T--)
	{
		diffusion();
		clean(machine);
	}
	
	int answer = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			answer += dust[i][j];
		}
	}

	cout << answer + 2;
}