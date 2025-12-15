// 요격 시스템

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    // 오름차순
    if(a[1] < b[1])
        return true;
    else
        return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), comp);
    
    int e = 0;
    for(int i = 0; i < targets.size(); i++) {
        // 다음의 s가 앞에 요격한 거 e보다 크거나 같다면 새로운 미사일이 필요
        if(targets[i][0] >= e) {
            e = targets[i][1];
            answer++;
        }
    }
    
    return answer;
}
