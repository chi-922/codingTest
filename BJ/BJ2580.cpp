#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));  // 9x9 크기 벡터 선언
vector<pair<int, int>> coords;
int temp;
bool solved = false;   // 답 여러 개일 경우

bool check(int row, int col, int num) {
    // 9개 구역 중 어디인지 몫으로 판단
    int modRow = row / 3;
    int modCol = col / 3;

    // 3 by 3
    for (int i = 3 * modRow; i < 3 * (modRow + 1); i++)
    {
        for (int j = 3 * modCol; j < 3 * (modCol + 1); j++)
        {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }

    // row
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num) {
            return false;
        }
    }

    // col
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num) {
            return false;
        }
    }

    return true;
}

void dfs(int dep) {
    if (dep == coords.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        solved = true;
        return;
    }

    int row = coords[dep].first;
    int col = coords[dep].second;

    for (int i = 1; i < 10 ; i++)
    {
        if (check(row, col, i)) {
            sudoku[row][col] = i;
            dfs(dep + 1);
            if (solved) return;  // 이미 찾았으면 더 탐색하지 않음
            sudoku[row][col] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> temp;
            sudoku[i][j] = temp;
            if (temp == 0) {
                coords.emplace_back(i, j);
            }
        }
    }

    dfs(0);
}