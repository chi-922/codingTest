#include <iostream>

using namespace std;

int N, M, temp;
long long cnt[1001];
long long sum, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sum += temp;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= M; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}

	cout << cnt[0] + ans;
}