#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, temp;
vector<int> tree;
long long answer = 0;

long long binarySearch() {
	int start = 0;
	int end = tree[n - 1];
	int mid;

	while (start <= end)
	{
		long long sum = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}

		if (sum >= m) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return end;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		tree.push_back(temp);
	}

	sort(tree.begin(), tree.end());

	cout << binarySearch();
}