#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<string>> container(52, vector<string>(52, "x"));
int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void jigae(string ch) {
    vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    queue<pair<int, int>> box;
    
    while(!q.empty())
    {
        int cr = q.front().first; int cc = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = cr + dr[d]; int nc = cc + dc[d];
            if (nr < 0 || nr >= n + 1 || nc < 0 || nc >= m + 1) continue;
            if (visited[nr][nc]) continue;
            if (container[nr][nc] == "x")
            {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
            if (container[nr][nc] == ch) {
                box.push({nr, nc});
                visited[nr][nc] = 1;
            }

        }
    }
    
    while(!box.empty())
    {
        int cr = box.front().first; int cc = box.front().second;
        box.pop();
        container[cr][cc] = "x";
    }
}

void krain(char ch) {
    string s = string(1, ch);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (container[i][j] == s) container[i][j] = "x";
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size() + 1;
    m = storage[0].size() + 1;
        
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            container[i][j] = storage[i - 1][j - 1];
        }
    }

    
    for (int order = 0; order < requests.size(); order++)
    {
        if (requests[order].size() == 1) jigae(requests[order]);
        else krain(requests[order][0]);
    }
    
    int answer = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (container[i][j] != "x") answer++;
        }
    }
    
    return answer;
}
