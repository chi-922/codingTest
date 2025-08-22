#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define D 1000000007
#define int long long

int n, m, k;
int arr[1000001];
vector<int> segmentTree;

int init(vector<int>& tree, int node, int st, int ed) {
	if (st == ed) return tree[node] = arr[st];
	
	int mid = (st + ed) / 2;

	return tree[node] = (init(tree, node * 2, st, mid) * init(tree, node * 2 + 1, mid + 1, ed)) % D;
}

void updateTree(vector<int>& tree, int node, int st, int ed, int idx, int value) {
	if (idx < st || idx > ed) return;

	if (st == ed) {
		tree[node] = value;
		return;
	}

	int mid = (st + ed) / 2;
	updateTree(tree, node * 2, st, mid, idx, value);
	updateTree(tree, node * 2 + 1, mid + 1, ed, idx, value);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % D;
}

int multiTree(vector<int>& tree, int node, int st, int ed, int left, int right) {
	if (left > ed || right < st) return 1;
	if (left <= st && ed <= right) return tree[node];

	int mid = (st + ed) / 2;
	return (multiTree(tree, node * 2, st, mid, left, right) * multiTree(tree, node * 2 + 1, mid + 1, ed, left, right)) % D;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp % D;
	}

	int height = ceil(log2(n));
	int size = 1 << (height + 1);

	segmentTree.resize(size, 0);

	init(segmentTree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1){
			updateTree(segmentTree, 1, 0, n - 1, b - 1, c);
		}
		else {
			cout << multiTree(segmentTree, 1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
}