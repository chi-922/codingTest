#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<string, int>> program;
	string str;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> str >> num;
		program.push_back({ str, num });
	}

	for (int i = 0; i < m; i++) {
		cin >> num;

		int left = 0, right = n - 1, mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;

			if (num <= program[mid].second)
				right = mid - 1;
			else
				left = mid + 1;
		}

		if (num > program[mid].second) {
			cout << program[mid + 1].first << '\n';
		}
		else
			cout << program[mid].first << '\n';
	}

	return 0;

}