// [PCCP 기출문제] 2번 석유 시추

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;
int area = 1;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
map<int, int> oil;

void bfs(int r, int c, vector<vector<int>>& visited, int& n, int& m, vector<vector<int>>& land)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = area;
    int cnt = 1;
    
    while(!q.empty())
    {
        int cr = q.front().first, cc = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = cr + dr[d], nc = cc + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (!land[nr][nc] || visited[nr][nc]) continue;
            q.push({nr, nc});
            visited[nr][nc] = area;
            cnt++;
        }
    }
    
    oil.insert({area, cnt});
    area++;
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] && !visited[i][j]) bfs(i, j, visited, n, m, land);
        }
    }
    
    int answer = 0;
    for (int j = 0; j < m; j++)
    {
        set<int> col;
        for (int i = 0; i < n; i++)
        {
            if(visited[i][j]) col.insert(visited[i][j]);
        }
        
        int sichu = 0;
        for (int element : col)
        {
            sichu += oil[element];
        }
        answer = max(answer, sichu);
    }
    
    return answer;
}
