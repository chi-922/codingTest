// 덧칠하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    // sort(section.begin(), section.end());

    int idx = section.size() - 1;
    int now = section[idx];
    
    while (now > 0 && idx >= 0)
    {
        if (now > section[idx])
        {
            now = section[idx];
        }
        else if (now < section[idx])
        {
            idx--;
            continue;
        }
        now -= m;
        answer++;
        idx--;
    }
    
    return answer;
}
