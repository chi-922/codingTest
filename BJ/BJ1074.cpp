#include <iostream>
using namespace std;

int solve(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);  // 사각형 한 변의 절반
    int area = half * half;

    // 사분면 계산 (0: 왼위, 1: 오위, 2: 왼아래, 3: 오아래)
    if (r < half && c < half) {
        return solve(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        return area + solve(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        return area * 2 + solve(n - 1, r - half, c);
    }
    else {  // r >= half && c >= half
        return area * 3 + solve(n - 1, r - half, c - half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, r, c;
    cin >> N >> r >> c;

    cout << solve(N, r, c);
    return 0;
}
