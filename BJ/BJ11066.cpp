#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
int t;
int dp[501][501];
int sum[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a; // 1~x ��° ���ϱ����� ũ�� ��
        }

        for (int i = 1; i < k; i++) {
            // i�� ���ؾ��ϴ� ������ �ǹ� : i=1�̸� 1~2��° ���� ���� ��ĥ ���� �ǹ�
            for (int x = 1; x <= k - i; x++) {
                //x�� ��ġ�� ������ ���� �κ��� �ǹ� : i�� ������ �ǹ��ϹǷ� k-i������ ���ָ� k���� Ž���ϰ� �ȴ�.
                int y = x + i;
                dp[x][y] = INT_MAX; // x~y ��° ���ϵ��� ��ġ�µ� �ʿ��� �ּ� ���

                for (int mid = x; mid < y; mid++) {
                    // mid�� ���ؾ��ϴ� ������ �� �κ����� ������ �������� �ǹ�
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                    // dp[n][n]�� 0�̱� ������ sum[y] - sum[x-1]�� dp[x][y]�� ����
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}