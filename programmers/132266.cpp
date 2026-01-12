// 부대복귀

#include <string>
#include <vector>
#include <queue>

#define INTMAX 100000

using namespace std;

void dijkstra(vector<vector<int>>& adj, int& destination, vector<int>& dis) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[destination] = 0;
    pq.push({0, destination});
    
    while(!pq.empty()) {
        int load = pq.top().first, now = pq.top().second;
        pq.pop();
        
        if (dis[now] < load) continue;
        
        for(int& next: adj[now]) {
            if (load + 1 >= dis[next]) continue;
            
            dis[next] = load + 1;
            pq.push({load + 1, next});
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < roads.size(); ++i) {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    
    vector<int> dis (n + 1, INTMAX);
    dijkstra(adj, destination, dis);
    
    for (int& s : sources) {
        if (dis[s] == INTMAX) dis[s] = -1;
        answer.push_back(dis[s]);
    }
    
    return answer;
}
