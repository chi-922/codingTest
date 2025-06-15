#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;  // 참조로 입력 받음

    vector<int> dp(n, 1);  // dp 초기화

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sum = max(sum, dp[i]);
    }

    cout << sum;
    return 0;
}