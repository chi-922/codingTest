#include <iostream>

using namespace std;

int N;
int meeting[15][2];
int dp[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> meeting[i][0] >> meeting[i][1];
	}

	for (int i = 0; i < N; i++)
	{
		if (i + meeting[i][0] <= N)
			dp[i + meeting[i][0]] = max(dp[i + meeting[i][0]], dp[i] + meeting[i][1]);

		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[N];
}