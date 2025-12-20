// 두 원 사이의 정수 쌍

#include <cmath>

using namespace std;

long long answer = 0;

long long solution(int r1, int r2) {
    long long powr1 = r1 * (long long)r1;
    long long powr2 = r2 * (long long)r2;
    
    // r1^2 <= x^2 + y^2 <= r2^2
    for (long long x = -r2; x <= r2; x++) {
        long long y1 = (long long)sqrt(powr1 - x * x);
        long long y2 = (long long)sqrt(powr2 - x * x);
        
        if (x * x + y1 * y1 < powr1) y1 += 1;
        if (y1 <= 0) y1 = 0;
        
        answer += (y2 - y1 + 1) * 2;
      
        if (y1 == 0) answer -= 1;
    }
    
    return answer;
}
