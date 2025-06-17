#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    vector<vector<int>> dp;

    cin >> s1 >> s2;

    s1 = "0" + s1;
    s2 = "0" + s2;

    // s1이 행, s2가 열
    dp.resize(s2.size(), vector<int>(s1.size()));

    // s2 한 글자씩 s1 순회
    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s1[j] == s2[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s2.size() - 1][s1.size() - 1];
}