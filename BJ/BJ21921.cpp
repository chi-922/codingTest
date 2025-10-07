#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> visiter(n);

	for (int i = 0; i < n; i++)
	{
		cin >> visiter[i];
	}

	int window = accumulate(visiter.begin(), visiter.begin() + x, 0);
	int maxv = window;
	int cnt = 1;

	for (int i = x; i < n; i++)
	{
		window -= visiter[i - x];
		window += visiter[i];

		if (window > maxv) {
			maxv = window;
			cnt = 1;
		}
		else if (window == maxv) {
			cnt++;
		}
	}

	if (maxv == 0) cout << "SAD";
	else cout << maxv << '\n' << cnt;
}