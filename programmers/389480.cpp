// 완전범죄

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    if (a[0] - a[1] == b[0] - b[1]) return a[0] / a[1] > b[0] / b[1];
    else return a[0] - a[1] > b[0] - b[1];
}

int solution(vector<vector<int>> info, int n, int m) {
    sort(info.begin(), info.end(), compare);
    
    int aCase = 0, bCase = 0;
    
    for (int i = 0; i < info.size(); i++)
    {
        int a = info[i][0], b = info[i][1];
        
        // b가 훔칠 경우
        if (m - bCase > b)
        {
            bCase += b;
        } else if (n - aCase > a)
        {
            aCase += a;
        } else return -1;
    }
    return aCase;
}
