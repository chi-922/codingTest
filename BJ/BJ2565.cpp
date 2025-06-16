#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<pair<int, int>> wire;
	int dp[101];  // dp[i] = i��° �������� ���������� ���� ���� LIS ����
	int maxValue = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int first, second;
		cin >> first >> second;
		wire.push_back(make_pair(first, second));
	}

	sort(wire.begin(), wire.end()); // A������ ���� �������� ����

	for (int i = 0; i < N; i++) {
		dp[i] = 1;  // �ڱ� �ڽŸ� ����ϴ� ��� = ���� 1
		for (int j = 0; j < i; j++) {
			if (wire[i].second > wire[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxValue = max(maxValue, dp[i]);
	}

	cout << N - maxValue;  // �����ؾ� �� ������ ��
}