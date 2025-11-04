// 산 모양 타일링

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int MOD = 10007;
    
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    
    a[0] = 0;   // a[k] = k번째 아래 방향 정삼각형까지 덮되, k번째 아래 방향 정삼각형을 덮는 방법이 왼쪽 평행사변형
    b[0] = 1;   // b[k] = k번째 아래 방향 정삼각형까지 덮되, k번째 아래 방향 정삼각형을 덮는 방법이 왼쪽 평행사변형이 아닌 경우
    
    // 동적 계획법으로 a[k]와 b[k] 계산
    for (int k = 1; k <= n; ++k) 
    {
        if (tops[k - 1] == 1)   // tops[k-1] == 1 -> 정삼각형이 덮인 경우
        { 
            a[k] = (a[k-1] + b[k-1]) % MOD;
            b[k] = (2 * a[k-1] + 3 * b[k-1]) % MOD;
        } 
        else   // tops[k-1] == 0 -> 정삼각형이 덮이지 않은 경우
        { 
            a[k] = (a[k-1] + b[k-1]) % MOD;
            b[k] = (a[k-1] + 2 * b[k-1]) % MOD;
        }
    }

    // 결과값은 a[n] + b[n] (10007로 나눈 나머지)
    return (a[n] + b[n]) % MOD;
}
