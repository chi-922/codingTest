#include <iostream>

using namespace std;

int dp[35];  // 원래 기존 타일 dp
int ddpp[35];  // 두 타일이 각각 앞에서, 뒤에서 읽기 시작했을 때 똑같이 읽히는 쌍 dp

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 1; dp[2] = 3; dp[3] = 5; dp[4] = 11;
    if (n > 4) {
        for (int i = 5; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] * 2;
        }
    }

    ddpp[1] = 1; ddpp[2] = 3; ddpp[3] = 1; ddpp[4] = 5;
    if (n > 4) {
        for (int i = 5; i <= n; i++) {
            ddpp[i] = ddpp[i - 2] + ddpp[i - 4] * 2;
        }
    }

    cout << (dp[n] + ddpp[n]) / 2;
}
