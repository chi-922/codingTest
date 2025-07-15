#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int m, n, h;
vector<vector<vector<int>>> tomatos;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int bfs() {
    queue<array<int, 3>> q;
    int days = -1;  // 처음 시작도 하루로 간주됨 (마지막에 +1 보정)

    // 초기 익은 토마토 큐에 넣기
    for (int z = 0; z < h; ++z)
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
                if (tomatos[z][y][x] == 1)
                    q.push({ z, y, x });

    while (!q.empty()) {
        int sz = q.size();
        days++;  // 하루 경과

        while (sz--) {
            auto [z, y, x] = q.front(); q.pop();

            for (int d = 0; d < 6; d++) {
                int nz = z + dz[d];
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (nz < 0 || nz >= h || ny < 0 || ny >= m || nx < 0 || nx >= n)
                    continue;

                if (tomatos[nz][ny][nx] == 0) {
                    tomatos[nz][ny][nx] = 1;
                    q.push({ nz, ny, nx });
                }
            }
        }
    }

    // 검사: 아직 안 익은 토마토 있는지
    for (int z = 0; z < h; z++)
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (tomatos[z][y][x] == 0)
                    return -1;

    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> h;

    tomatos.resize(h, vector<vector<int>>(m, vector<int>(n)));

    for (int z = 0; z < h; z++)
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                cin >> tomatos[z][y][x];

    cout << bfs();
    return 0;
}

// 구조체 풀이
/*
#include <iostream>
#include <queue>

using namespace std;

// 토마토의 좌표값
typedef struct coordinate {
    int x, y, z;
} xyz;


int M, N, H, tomato; 
int tomato_box[101][101][101];
int visited[101][101][101] = {}; // 전부 0으로 초기화
queue<xyz> q;

int day = 0; // 토마토 익는 날 계산

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };


int bfs() {
    while (!q.empty()) {
        // 익은 토마토 위치
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_z = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            int nz = now_z + dz[i];

            // 범위 밖이면 continue
            if (nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H) continue;

            // 안 익은 토마토가 있고 방문한 적이 없으면 익은 토마토로 바꾸고 queue에 넣어주기
            if (tomato_box[nz][ny][nx] == 0 and visited[nz][ny][nx] == -1) {
                xyz add_tomato;

                tomato_box[nz][ny][nx] = 1;
                add_tomato.x = nx;
                add_tomato.y = ny;
                add_tomato.z = nz;

                q.push(add_tomato);
                
                visited[nz][ny][nx] = visited[now_z][now_y][now_x] + 1;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (tomato_box[h][n][m] == 0) return -1; // 토마토가 모두 익지 못하는 경우
                day = max(day, visited[h][n][m]);
            }
        }
    }


    return day;
}

int main() {
    cin >> M >> N >> H;
    fill_n(&tomato_box[0][0][0], 101 * 101 * 101, -1);  // 아직 입력 받지 않았기에 토마토 없음!

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> tomato;
                tomato_box[h][n][m] = tomato;

                xyz tomato_coord;
                tomato_coord.x = m;
                tomato_coord.y = n;
                tomato_coord.z = h;

                if (tomato == 1) {  // 익은 토마토 정보는 queue에 저장하기
                    q.push(tomato_coord);
                }
                if (tomato == 0) visited[h][n][m] = -1;	// 토마토가 전부 익었을 경우를 대비해서 
            }
        }
    }

    cout << bfs();

    return 0;
}
*/