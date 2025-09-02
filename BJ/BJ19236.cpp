#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Pos {
    int r, c;
};

int maxSize = 0;
int dirr[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dirc[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

const int SHARK = -1;

// ����� �̵�
void movingFish(vector<vector<pair<int, int>>>& board, vector<Pos>& whereFish) {
    for (int i = 1; i <= 16; i++) {
        if (whereFish[i].r == -1) continue; // ���� ������ ��ŵ
        int r = whereFish[i].r;
        int c = whereFish[i].c;
        int d = board[r][c].second;

        for (int t = 0; t < 8; t++) {
            int nr = r + dirr[d];
            int nc = c + dirc[d];
            if (0 <= nr && nr <= 3 && 0 <= nc && nc <= 3 && board[nr][nc].first != SHARK) {
                board[r][c].second = d;

                int target = board[nr][nc].first; // 0 or �ٸ� �����
                swap(board[r][c], board[nr][nc]);

                whereFish[i] = { nr, nc };
                if (target > 0) {
                    whereFish[target] = { r, c };
                }
                break;
            }
            d = d % 8 + 1; // 45�� ȸ��
        }
    }
}

// DFS
void dfs(int curr, int curc, int curd,
    vector<vector<pair<int, int>>> board,
    vector<Pos> whereFish,
    int curw) {

    movingFish(board, whereFish);

    for (int step = 1; step <= 3; step++) {
        int nr = curr + dirr[curd] * step;
        int nc = curc + dirc[curd] * step;
        if (nr < 0 || nr > 3 || nc < 0 || nc > 3) break;
        if (board[nr][nc].first == 0) continue; // ��ĭ�̸� �ǳʶٰ� �� �ָ�

        auto newboard = board;
        auto newwhere = whereFish;

        // ���� ��� �ڸ� ����
        newboard[curr][curc] = { 0, 0 };

        int fish = newboard[nr][nc].first;
        int nextd = newboard[nr][nc].second;

        newwhere[fish] = { -1, -1 }; // ���� ó��
        newboard[nr][nc] = { SHARK, 0 }; // ��� �̵�

        dfs(nr, nc, nextd, newboard, newwhere, curw + fish);
    }

    maxSize = max(maxSize, curw);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<pair<int, int>>> board(4, vector<pair<int, int>>(4));
    vector<Pos> whereFish(17);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num, dir;
            cin >> num >> dir;
            board[i][j] = { num, dir };
            whereFish[num] = { i, j };
        }
    }

    int firstNum = board[0][0].first;
    int firstd = board[0][0].second;

    maxSize = firstNum;
    whereFish[firstNum] = { -1, -1 }; // ù ����� ����
    board[0][0] = { SHARK, 0 }; // ��� ǥ��

    dfs(0, 0, firstd, board, whereFish, maxSize);

    cout << maxSize;
}
