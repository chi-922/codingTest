#include <iostream>
#include <vector>
#include <math.h>
#include <climits>  // INT_MAX, INT_MIN »ç¿ë

using namespace std;

vector<int> arr;

struct Node {
	int mn;
	int mx;
};

const int INF = INT_MAX;
const int NINF = INT_MIN;

Node combine(Node& a, Node& b) {
	return { min(a.mn, b.mn), max(a.mx, b.mx) };
}

void build(vector<Node>& tree, int node, int st, int ed) {
	if (st == ed) {
		tree[node] = { arr[st], arr[st] };
		return;
	}

	int mid = (st + ed) / 2;
	build(tree, node * 2, st, mid);
	build(tree, node * 2 + 1, mid + 1, ed);
	tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
}

Node query(vector<Node>& tree, int node, int st, int ed, int left, int right) {
	if (right < st || ed < left) return { INF, NINF };
	if (left <= st && ed <= right) return tree[node];

	int mid = (st + ed) / 2;
	Node ql = query(tree, node * 2, st, mid, left, right);
	Node qr = query(tree, node * 2 + 1, mid + 1, ed, left, right);
	return combine(ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	arr.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int height = ceil(log2(n));
	int size = 1 << (height + 1);
	vector<Node> segment(size, {INF, NINF});
	build(segment, 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		Node ans = query(segment, 1, 0, n - 1, a - 1, b - 1);
		cout << ans.mn << ' ' << ans.mx << '\n';
	}
}