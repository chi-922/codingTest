#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
vector<vector<int>> black;
vector<vector<int>> white;
string line;
int answer = 10e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	black.resize(n + 1, vector<int>(m + 1, 0));
	white.resize(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			int idx = (i + j) % 2;
			int isB = (line[j] == 'B' ? 1 : 0);
			int isW = (line[j] == 'W' ? 1 : 0);

			black[i + 1][j + 1] = black[i + 1][j] + black[i][j + 1] - black[i][j] + (idx == 0 ? isW : isB);
			white[i + 1][j + 1] = white[i + 1][j] + white[i][j + 1] - white[i][j] + (idx == 0 ? isB : isW);
		}
	}

	for (int i = 0; i <= n - k; i++)
	{
		for (int j = 0; j <= m - k; j++)
		{
			int answerB = black[i + k][j + k] - black[i][j + k] - black[i + k][j] + black[i][j];
			int answerW = white[i + k][j + k] - white[i][j + k] - white[i + k][j] + white[i][j];
			int temp = min(answerB, answerW);
			answer = min(answer, temp);
		}
	}

	cout << answer;
}