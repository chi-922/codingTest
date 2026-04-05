// 노란불 신호등

#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    vector<int> sums(signals.size(), 0);
    // 신호등 최소공배수 구하자 -> 최소공배수 동안만 확인하면돼
    int lcm = 1;
    for(int i = 0; i < signals.size(); i++) {
        int sum = signals[i][0] + signals[i][1] + signals[i][2];
        sums[i] = sum;
        lcm = lcm * sum / gcd(lcm, sum);
    }
    
    int sec = signals[0][0] + 1;

    while(sec <= lcm) {
        bool flag = true;
        for (int i = 1; i < signals.size(); i++) {
            if ((sec % sums[i]) <= signals[i][0] || (sec % sums[i]) >= signals[i][0] + signals[i][1] + 1) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            answer = sec;
            break;
        }
        
        if ((sec % sums[0]) < signals[0][0] + signals[0][1]) sec += 1;
        else sec += (signals[0][0] + signals[0][2] + 1);
    }
    
    if (answer == 0) answer = -1;
    return answer;
}
