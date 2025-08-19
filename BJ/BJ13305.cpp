#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> road(n - 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> road[i];
	}

	vector<int> oil(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> oil[i];
	}

	int cheap = oil[0];
	int money = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (oil[i] <= cheap) {
			money += oil[i] * road[i];
			if (oil[i] < cheap) cheap = oil[i];
		}
		else {
			money += cheap * road[i];
		}
	}

	cout << money;
}