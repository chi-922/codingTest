// 카카오프렌즈 컬러링북

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs (int& i, int& j, vector<vector<int>>& picture, vector<vector<int>>& visited, int& m, int& n) {
    int area = 1;
    int color = picture[i][j];
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    
    while(!q.empty())
    {
        int cr = q.front().first, cc = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++)
        {
            int nr = cr + dr[d], nc = cc + dc[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (visited[nr][nc] || !picture[nr][nc]) continue;
            if (picture[nr][nc] == color)
            {
                area++;
                visited[nr][nc] = 1;
                q.push({nr, nc});   
            }
        }
    }
    
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] && !visited[i][j]) {
                int temp;
                temp = bfs(i, j, picture, visited, m, n);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, temp);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
