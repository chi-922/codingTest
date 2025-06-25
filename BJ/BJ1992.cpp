#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> board;
int n;

void quadTree(int x, int y, int size) {

	int color = board[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {

			if (color != board[i][j]) {
				cout << "(";
				quadTree(x, y, size / 2);
				quadTree(x, y + (size / 2), size / 2);
				quadTree(x + (size / 2), y, size / 2);
				quadTree(x + (size / 2), y + (size / 2), size / 2);
				cout << ")";
				return;
			}
		}
	}
	if (color == 0) cout << 0;
	else cout << 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	board.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	quadTree(0, 0, n);
	return 0;
}