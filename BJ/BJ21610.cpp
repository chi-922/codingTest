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
vector<vector<int>> basket;  // �� ��
vector<pair<int, int>> clouds;  // ���� ���� ��ġ ���
vector<vector<bool>> hadCloudThisTurn;  // �̹� �Ͽ� ������ �־���(�Ҹ� ���) ǥ��

// ��ǥ�� N���� wrap (���� ���)
inline int wrap(int x) {
    // (x % N + N) % N
    int r = x % N;
    if (r < 0) r += N;
    return r;
}

// 1) ���� �̵� + �� ������, 2) ������ ���� ����, 3) �̹� �� ���� ��ġ ���
void rainAndCopy(int dir, int s) {
    // �̵� ����� ���� �� �����̳�
    vector<pair<int, int>> moved;
    moved.reserve(clouds.size());

    // 1) ���� �̵� + ��(+1)
    for (auto& p : clouds) {
        int r = p.first, c = p.second;
        int nr = wrap(r + dr[dir] * s);
        int nc = wrap(c + dc[dir] * s);
        basket[nr][nc] += 1;
        moved.emplace_back(nr, nc);
    }

    // 2) ������ ����: �� ���� ���� ĭ���� �밢�� 4������ �� ���� ����ŭ +1
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

    // 3) �̹� �Ͽ� ������ �ִ� ĭ ǥ��
    hadCloudThisTurn.assign(N, vector<bool>(N, false));
    for (auto& p : moved) {
        hadCloudThisTurn[p.first][p.second] = true;
    }

    // clouds�� �̵� ����� ����
    clouds.swap(moved);
}

// 4) ���ο� ���� ����: ���� 2 �̻��̰� �̹� �� ������ ������ ĭ
//    -> �� -2 �ϰ� ���� ����. ���� ������ ��������� clouds�� ���� ä��
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
