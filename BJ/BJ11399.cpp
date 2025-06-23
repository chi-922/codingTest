#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int>line;
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		line.push_back(k);
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < n; i++) {
		answer += line[i] * (n - i);
	}

	cout << answer;
}