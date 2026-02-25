#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	// (void)freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	while (tc--) {
		int h, w;
		cin >> h >> w;
		
		int cnt = 0;
		vector<string> col;

		// 한 행에 . 이 없다면 행 골라져서 칠해진 거
		// 있으면 col로 보내자
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;

			if (s.find('.') != -1) {
				// .이 있다면
				col.push_back(s);
			}
			else cnt++;
		}

		// 남은 col에서 시계방향으로 돌려봤을 때 #행 갯수 추가
		if (!col.empty()) {
			for (int j = 0; j < w; j++) {
				bool isHash = true;
				for (int i = 0; i < col.size(); i++) {
					if (col[i][j] == '.') {
						isHash = false;
						break;
					}
				}
				if (isHash) cnt++;
			}
		}
		else {
			cnt = min(h, w);
		}

		cout << cnt << endl;
	}
	
	return 0;
}