#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node {
	int mn;
	int mx;
};

vector<int> video;
vector<Node> tree;

Node combine(Node& a, Node& b) {
	return { min(a.mn, b.mn), max(a.mx, b.mx) };
}

Node init(vector<Node>& tr, int node, int st, int ed) {
	if (st == ed) {
		return tr[node] = { st, st };
	}

	int mid = (st + ed) / 2;
	Node left = init(tr, node * 2, st, mid);
	Node right = init(tr, node * 2 + 1, mid + 1, ed);
	return tr[node] = combine(left, right);
}

void change(vector<Node>& tr, int node, int st, int ed, int idx, int value) {
	if (idx < st || idx > ed) return;
	if (st == ed) {
		tr[node] = { value, value };
		return;
	}
	
	int mid = (st + ed) / 2;
	change(tr, node * 2, st, mid, idx, value);
	change(tr, node * 2 + 1, mid + 1, ed, idx , value);
	tr[node] = combine(tr[node * 2], tr[node * 2 + 1]);
}

Node checkVideo(vector<Node>& tr, int node, int st, int ed, int left, int right) {
	if (left > ed || right < st) return {100001, -1};
	if (left <= st && right >= ed) return tr[node];

	int mid = (st + ed) / 2;
	Node checkL = checkVideo(tr, node * 2, st, mid, left, right);
	Node checkR = checkVideo(tr, node * 2 + 1, mid + 1, ed, left, right);
	if (checkL.mn == 100001) return checkR;
	if (checkR.mn == 100001) return checkL;
	return combine(checkL, checkR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		
		int height = ceil(log2(n));
		int size = 1 << (height + 1);
		
		tree.clear();
		tree.resize(size);
		video.clear();
		video.resize(n, 0);

		for (int i = 0; i < n; i++)
		{
			video[i] = i;
		}

		init(tree, 1, 0, n - 1);

		for (int i = 0; i < k; i++)
		{
			int q, a, b;
			cin >> q >> a >> b;

			if (q == 0) {
				int temp = video[a];
				change(tree, 1, 0, n - 1, a, video[b]);
				video[a] = video[b];
				change(tree, 1, 0, n - 1, b, temp);
				video[b] = temp;
			}
			else {
				Node res = checkVideo(tree, 1, 0, n - 1, a, b);
				cout << ((res.mn == a && res.mx == b) ? "YES\n" : "NO\n");
			}
		}
	}
}