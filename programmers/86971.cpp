// 전력망 둘로 나누기

#include <string>
#include <vector>
#include <queue>
#include <cstdlib> 

using namespace std;
int answer = 100;
vector<vector<int>> tree;

void divided (int& a, int& b, int& n) {
    vector<int> visited(n + 1, 0);
    visited[a] = 1;
    queue<int> q;
    q.push(a);
    
    int cnt = 1;
    
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        for (auto next : tree[now])
        {
            if (visited[next]) continue;
            if (next == b) continue;
            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }
    
    if (abs(n - 2 * cnt) < answer) answer = abs(n - 2 * cnt);
}

int solution(int n, vector<vector<int>> wires) {
    tree.resize(n + 1);
    
    for (auto wire : wires)
    {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    for (auto wire : wires)
    {
        divided(wire[0], wire[1], n);
        if (answer == 0) break;
    }
    
    return answer;
}
