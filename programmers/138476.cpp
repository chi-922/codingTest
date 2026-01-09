// 귤 고르기

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    map<int, int> m;
    
    for (int& t: tangerine) {
        if (m.find(t) == m.end()) m[t] = 1;
        else m[t]++;
        
        if (m[t] >= k) {
            answer = 1;
            return answer;
        }
    }
    
    for (auto it = m.begin(); it != m.end(); ++it) pq.push({it->second, it->first});
    
    
    int package = 0;
    while(true) {
        int num = pq.top().first;
        pq.pop();
        package += num;
        answer++;
        if (package >= k) break;
    }
    
    return answer;
}
