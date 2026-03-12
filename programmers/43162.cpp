// 네트워크

#include <vector>
#include <queue>

using namespace std;

vector<int> visited;

void bfs(int st, vector<vector<int>>& computers) {
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < computers[now].size(); i++) {
            if (i == now) continue;
            if (computers[now][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}
