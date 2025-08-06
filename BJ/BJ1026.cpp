#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n, 0);
	vector<int> b(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += a[i] * b[i];
	}
	
	cout << ans;
}