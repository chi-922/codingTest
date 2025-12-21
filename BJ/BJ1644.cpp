#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<bool> isPrime(n + 1, true);
	vector<int> prime;

	if (n == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 2; i * i <= n; i++) //소수 구하기 - 에라토스테네스의 체
	{
		for (int j = i * 2; j <= n; j += i)
			isPrime[j] = false;
	}

	for (int i = 2; i <= n; i++) // 소수들을 벡터에 담음 -> 계산 편리
	{
		if (isPrime[i])prime.push_back(i);
	}

	// 누적합
	vector<int> con = { 0 };
	int p2 = 0;
	for (int i = 0; i < prime.size(); i++) {
		int temp = con[i] + prime[i];
		con.push_back(temp);
		// 누적합 막 n부근인 인덱스 찾기
		if (temp >= n && !p2) p2 = i + 1;
	}

	int answer = 0;
	int p1 = 0;
	while (true) {
		if (p1 < 0) p1 = 0;
		if (p2 >= con.size() || p1 > p2) break;
		if (prime[p2 - 1] > n) break;

		if (con[p2] - con[p1] == n) {
			answer++;
			p2++;
			p1--;
		}
		else if (con[p2] - con[p1] > n) p1++;
		else if (con[p2] - con[p1] < n) p2++;
	}

	cout << answer;

	return 0;
}