#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 10001000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> distance(n + 1, vector<int>(n + 1, INF));
        
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        distance[a][b] = 1;
        distance[b][a] = 1;
    } //a와 b가 친구인 경우
    
    for(int K = 1; K <= n; K++)
        for(int i = 1; i <= n; i++)
            for(int j = 1;j <= n; j++)
                //K를 경유해 가는 경우가 더 빠르다면 갱신
                distance[i][j] = min(distance[i][j], distance[i][K] + distance[K][j]);
    
    vector<int> answer(n + 1, INF);
    for(int K = 1; K <= n; K++) {
        for(int i = 1; i <= n; i++)
            answer[K] += distance[K][i];
        answer[K] -= distance[K][K]; //자신으로 가는 경로는 빼줌
    }
    
    int min = answer[1];
    int index = 1;
    for(int i = 2; i <= n; i++) {
        if(answer[i] < min) {
            min = answer[i];
            index = i;
        }
    }
            
    cout << index;
}
