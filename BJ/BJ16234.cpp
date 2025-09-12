#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> country;
vector<vector<int>> visited;
int n, l, r;
int cnt = 0;
bool flag = true;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs() {
    visited.assign(n, vector<int>(n, 0));
    int unitCountry = 0;
    bool moved = false;

    // 연합국별 합계와 국가 수
    vector<int> sumPop;
    vector<int> cntPop;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                unitCountry++;
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = unitCountry;

                int sum = country[i][j];
                int num = 1;
                vector<pair<int, int>> members;
                members.push_back({ i,j });

                while (!q.empty()) {
                    int cr = q.front().first, cc = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (visited[nr][nc]) continue;
                        int diff = abs(country[cr][cc] - country[nr][nc]);
                        if (diff >= l && diff <= r) {
                            visited[nr][nc] = unitCountry;
                            q.push({ nr,nc });
                            members.push_back({ nr,nc });
                            sum += country[nr][nc];
                            num++;
                        }
                    }
                }

                // 연합이 2개 이상이면 인구 재배치
                if (members.size() > 1) {
                    moved = true;
                    int avg = sum / num;
                    for (auto& cell : members) {
                        country[cell.first][cell.second] = avg;
                    }
                }
            }
        }
    }

    if (!moved) {
        flag = false; // 더 이상 이동 없음
        return;
    }

    cnt++; // 하루 증가
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    country.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> country[i][j];
        }
    }

    while (flag) {
        bfs();
    }

    cout << cnt << '\n';
    return 0;
}
