// 서버 증설 횟수

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    
    for (const int& num : players) {
        int cnt = 0;
        int s = q.size();
        while(cnt < s) {
            int temp = q.front();
            q.pop();
            if (temp > 1) q.push(temp - 1);
            cnt++;
        }
        
        int server = num / m;
        s = q.size();
        
        if (server && s < server) {
            for (int i = 0; i < server - s; ++i) {
                q.push(k);
                answer++;
            }
        }
        
        
    }
    return answer;
}
