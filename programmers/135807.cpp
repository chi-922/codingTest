// 숫자 카드 나누기

#include <vector>
#include <numeric>   // gcd
using namespace std;

int gcdOfArr(const vector<int>& arr) {
    int g = 0;                  // gcd(0, x) = x
    for (int x : arr) {
        g = gcd(g, x);
        if (g == 1) return 1;   // 더 줄어들 여지 없음
    }
    return g;
}

bool isInvalid(int d, const vector<int>& arr) {
    if (d <= 1) return true;          // d는 2 이상
    for (int v : arr)
        if (v % d == 0) return true;  // 하나라도 나눠지면 탈락
    return false;                     // 끝까지 못 나누면 통과
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = gcdOfArr(arrayA);
    int gcdB = gcdOfArr(arrayB);

    int candA = isInvalid(gcdA, arrayB) ? 0 : gcdA;
    int candB = isInvalid(gcdB, arrayA) ? 0 : gcdB;

    return max(candA, candB);
}
