#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	(void)freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	while (tc--) {
		int close;
		cin >> close;

		if (close == 1) {
			cout << 0 << endl;
			continue;
		}
		else {
			int half = close / 2;

			if (close % 2 != 0) cout << 4;

			for (int i = 0; i < half; i++) {
				cout << 8;
			}

			cout << endl;
		}
	}

	return 0;
}