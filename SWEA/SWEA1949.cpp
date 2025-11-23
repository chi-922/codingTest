#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, K;
vector<vector<int>> mountain;
vector<vector<int>> visited;
int max_len = 0;

int dirs[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};

void dfs(int x, int y, int route, bool work){
    visited[x][y] = 1;

    for(auto &d : dirs){
        int nx = x + d[0];
        int ny = y + d[1];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(visited[nx][ny]) continue;

        // 이미 공사를 했고 내리막도 아니면 이동 불가
        if(work && mountain[nx][ny] >= mountain[x][y]){
            max_len = max(max_len, route);
            continue;
        }

        // 아직 공사를 안 한 경우
        if(mountain[nx][ny] >= mountain[x][y]){
            // depth = 1 ~ K 만큼 깎기 시도
            for(int depth = 1; depth <= K; depth++){
                // K만큼 깎았는데도 여전히 못 내려가면 중단
                if(depth == K && mountain[nx][ny] - depth >= mountain[x][y]){
                    max_len = max(max_len, route);
                    break;
                }

                mountain[nx][ny] -= depth;
                if(mountain[nx][ny] < mountain[x][y]){
                    dfs(nx, ny, route + 1, true);
                }
                mountain[nx][ny] += depth;
            }
        }
        else{
            // 그냥 내리막이면 이동
            dfs(nx, ny, route + 1, work);
        }
    }

    visited[x][y] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;

    for(int tc = 1; tc <= test; tc++){
        cin >> N >> K;

        mountain.assign(N, vector<int>(N));
        visited.assign(N, vector<int>(N, 0));

        int top_height = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> mountain[i][j];
                top_height = max(top_height, mountain[i][j]);
            }
        }

        vector<pair<int,int>> top;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mountain[i][j] == top_height){
                    top.emplace_back(i, j);
                }
            }
        }

        max_len = 0;

        for(auto &st : top){
            dfs(st.first, st.second, 1, false);
        }

        cout << "#" << tc << " " << max_len << "\n";
    }
}
