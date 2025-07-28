#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n;

	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> x;

	int cnt = 0;
	int i = 0, j = n - 1;

	while (i != j && i < j)
	{
		if (arr[i] + arr[j] > x) {
			j--;
		}
		else if (arr[i] + arr[j] == x) {
			cnt++; i++; j--;
		}
		else if (arr[i] + arr[j] < x) {
			i++;
		}
	}

	cout << cnt;
}