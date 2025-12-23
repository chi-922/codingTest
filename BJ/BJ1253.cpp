#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n <= 2) {
		cout << 0;
		return 0;
	}

	vector<long long> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int p1 = 0, p2 = 1;
	int num = 2;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		int l = 0, r = n - 1;
		while (l < r) {
			if (l == i) l++;
			else if (r == i) r--;
			else if (arr[l] + arr[r] < arr[i]) l++;
			else if (arr[l] + arr[r] > arr[i]) r--;
			else if (arr[l] + arr[r] == arr[i]) {
				answer++;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}