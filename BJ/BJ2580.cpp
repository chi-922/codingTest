#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));  // 9x9 ũ�� ���� ����
vector<pair<int, int>> coords;
int temp;
bool solved = false;   // �� ���� ���� ���

bool check(int row, int col, int num) {
    // 9�� ���� �� ������� ������ �Ǵ�
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
            if (solved) return;  // �̹� ã������ �� Ž������ ����
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