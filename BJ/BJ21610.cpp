#include <iostream>
#include <vector>
#include <numeric>   // std::accumulate
using namespace std;


struct Magic { int d, s; };

static const int dr[9] = { 0, 0,-1,-1,-1, 0, 1, 1, 1 };
static const int dc[9] = { 0,-1,-1, 0, 1, 1, 1, 0,-1 };

static const int diagR[4] = { -1,-1, 1, 1 };
static const int diagC[4] = { -1, 1,-1, 1 };

int N, M;
vector<vector<int>> basket;  // 물 양
vector<pair<int, int>> clouds;  // 현재 구름 위치 목록
vector<vector<bool>> hadCloudThisTurn;  // 이번 턴에 구름이 있었다(소멸 대상) 표시

// 좌표를 N으로 wrap (음수 대비)
inline int wrap(int x) {
    // (x % N + N) % N
    int r = x % N;
    if (r < 0) r += N;
    return r;
}

// 1) 구름 이동 + 비 내리기, 2) 물복사 버그 적용, 3) 이번 턴 구름 위치 기록
void rainAndCopy(int dir, int s) {
    // 이동 결과를 담을 새 컨테이너
    vector<pair<int, int>> moved;
    moved.reserve(clouds.size());

    // 1) 구름 이동 + 비(+1)
    for (auto& p : clouds) {
        int r = p.first, c = p.second;
        int nr = wrap(r + dr[dir] * s);
        int nc = wrap(c + dc[dir] * s);
        basket[nr][nc] += 1;
        moved.emplace_back(nr, nc);
    }

    // 2) 물복사 버그: 각 구름 도착 칸마다 대각선 4방향의 물 존재 수만큼 +1
    for (auto& p : moved) {
        int r = p.first, c = p.second;
        int add = 0;
        for (int k = 0; k < 4; ++k) {
            int nr = r + diagR[k];
            int nc = c + diagC[k];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                if (basket[nr][nc] > 0) add += 1;
            }
        }
        basket[r][c] += add;
    }

    // 3) 이번 턴에 구름이 있던 칸 표시
    hadCloudThisTurn.assign(N, vector<bool>(N, false));
    for (auto& p : moved) {
        hadCloudThisTurn[p.first][p.second] = true;
    }

    // clouds를 이동 결과로 갱신
    clouds.swap(moved);
}

// 4) 새로운 구름 생성: 물이 2 이상이고 이번 턴 구름이 없었던 칸
//    -> 물 -2 하고 구름 생성. 기존 구름은 사라졌으니 clouds를 새로 채움
void makeClouds() {
    vector<pair<int, int>> next;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!hadCloudThisTurn[i][j] && basket[i][j] >= 2) {
                basket[i][j] -= 2;
                next.emplace_back(i, j);
            }
        }
    }
    clouds.swap(next);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    basket.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> basket[i][j];
        }
    }

    vector<Magic> magic(M);
    for (int i = 0; i < M; ++i) {
        cin >> magic[i].d >> magic[i].s;
        magic[i].s %= N;
    }

    clouds.clear();
    clouds.emplace_back(N - 1, 0);
    clouds.emplace_back(N - 1, 1);
    clouds.emplace_back(N - 2, 0);
    clouds.emplace_back(N - 2, 1);

    hadCloudThisTurn.assign(N, vector<bool>(N, false));

    for (const auto& m : magic) {
        rainAndCopy(m.d, m.s);
        makeClouds();
    }

    long long result = 0;
    for (int i = 0; i < N; ++i) {
        result += accumulate(basket[i].begin(), basket[i].end(), 0LL);
    }
    cout << result << '\n';

    return 0;
}
