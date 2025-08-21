#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, m, k;
long long arr[1000000];

long long init(vector<long long>& tree, int node, int st, int ed) {
	if (st == ed) {
		return tree[node] = arr[st];
	}
	int mid = (st + ed) / 2;

	return tree[node] = init(tree, node * 2, st, mid) + init(tree, node * 2 + 1, mid + 1, ed);
}

void updateSegment(vector<long long>& tree, int node, int st, int ed, int idx, long long diff) {
	if (idx < st || idx > ed) return;
	tree[node] += diff;
	if (st != ed) {
		int mid = (st + ed) / 2;
		updateSegment(tree, node * 2, st, mid, idx, diff);
		updateSegment(tree, node * 2 + 1, mid + 1, ed, idx, diff);
	}
}

long long sumSegment(vector<long long>& tree, int node, int left, int right, int st, int ed) {
	if (left > ed || right < st) return 0;
	if (left <= st && right >= ed) return tree[node];
	
	int mid = (st + ed) / 2;
	return sumSegment(tree, node * 2, left, right, st, mid) + sumSegment(tree, node * 2 + 1, left, right, mid + 1, ed);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int height = ceil(log2(n));
	int size = 1 << (height + 1);

	vector<long long> segmentTree(size, 0);

	init(segmentTree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b;
		long long c;

		cin >> a >> b >> c;
		if (a == 1) {
			updateSegment(segmentTree, 1, 0, n - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else {
			cout << sumSegment(segmentTree, 1, b - 1, c - 1, 0, n - 1) << '\n';
		}
	}
}