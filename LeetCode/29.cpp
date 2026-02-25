// Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        
        if (divisor == 1) return dividend;

        // 컴퓨터의 음수표현 : MSB = 제일 왼쪽(최상위) 비트가 1이면 음수
        bool minous = (dividend >> 31) ^ (divisor >> 31);

        // 그냥 일반 양수의 나눗셈으로 가자
        long long dvd = llabs(dividend), dvs = llabs(divisor);
        int ans = 0;

        // dvd를 dvs로 뺄 수 있을만큼 빼자
        while (dvd >= dvs){
            long long tmp = dvs, m = 1;
            while ((tmp << 1) <= dvd){
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            ans += m;
        }
        return (minous ? -ans : ans);
    }
};
