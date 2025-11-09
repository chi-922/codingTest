// 지폐 접기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int w_max = wallet[0], w_min = wallet[0];
    int b_max = bill[0], b_min = bill[0];
    if (w_max < wallet[1]) w_max = wallet[1]; else w_min = wallet[1];
    if (b_max < bill[1]) b_max = bill[1]; else b_min = bill[1];
    while (true)
    {
        if (w_max >= b_max && w_min >= b_min) break;
        else {
            b_max /= 2;
            if (b_max < b_min) swap(b_max, b_min);
            answer++;
        }
    }
    return answer;
}
