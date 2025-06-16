#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<pair<int, int>> wire;
	int dp[101];  // dp[i] = i번째 전깃줄을 마지막으로 했을 때의 LIS 길이
	int maxValue = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int first, second;
		cin >> first >> second;
		wire.push_back(make_pair(first, second));
	}

	sort(wire.begin(), wire.end()); // A전봇대 기준 오름차순 정렬

	for (int i = 0; i < N; i++) {
		dp[i] = 1;  // 자기 자신만 사용하는 경우 = 길이 1
		for (int j = 0; j < i; j++) {
			if (wire[i].second > wire[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxValue = max(maxValue, dp[i]);
	}

	cout << N - maxValue;  // 제거해야 할 전깃줄 수
}