#include <iostream>

using namespace std;

int N, K, temp;
int sum[100001] = { 0, };
int result = -10e9;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}

	for (int i = K; i <= N; i++)
	{
		result = max(result, (sum[i] - sum[i - K]));
	}
	
	cout << result;
}