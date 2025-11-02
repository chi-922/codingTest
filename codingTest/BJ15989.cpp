#include <iostream>
#include <vector>

using namespace std;

int main() {
	// dp ¹®Á¦
	int T, n;
	cin >> T;

	int dp[10001][4];

    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 10000; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    while (T--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
    }

    return 0;
}