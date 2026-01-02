// 단속카메라

#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), compare);
    
    int ed = routes[0][1];
    for(int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > ed) {
            answer++;
            ed = routes[i][1];
        }
    }
    
    return answer;
}
