#include<iostream>

using namespace std;

int a[10];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] <= k) //현재 돈에 낼 수 있는 최대 화폐
		{
			cnt += k / a[i]; //그 지폐로 얼마나 낼 수 있는가
			k %= a[i]; //남은 돈
		}
	}
	cout << cnt;
}