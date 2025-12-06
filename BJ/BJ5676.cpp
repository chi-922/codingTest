#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, K;

int init(vector<int>& tree, int node, int st, int ed, vector<int>& arr) {
	if (st == ed) {
		int temp;
		if (arr[st] > 0) temp = 1;
		else if (arr[st] < 0) temp = -1;
		else temp = 0;

		return tree[node] = temp;
	}
	int mid = (st + ed) / 2;

	return tree[node] = init(tree, node * 2, st, mid, arr) * init(tree, node * 2 + 1, mid + 1, ed, arr);
}

void updateSegment(vector<int>& tree, int node, int st, int ed, int idx, int diff) {
	if (idx < st || idx > ed) return;
	tree[node] *= diff;
	if (st != ed) {
		int mid = (st + ed) / 2;
		updateSegment(tree, node * 2, st, mid, idx, diff);
		updateSegment(tree, node * 2 + 1, mid + 1, ed, idx, diff);
	}
}

int multiSegment(vector<int>& tree, int node, int left, int right, int st, int ed) {
	if (left > ed || right < st) return 1;
	if (left <= st && right >= ed) return tree[node];

	int mid = (st + ed) / 2;
	return multiSegment(tree, node * 2, left, right, st, mid) * multiSegment(tree, node * 2 + 1, left, right, mid + 1, ed);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> N >> K) {
		vector<int> arr(N);
		for (int i = 0; i < N; i++) cin >> arr[i];

		int height = ceil(log2(N));
		int size = 1 << (height + 1);

		vector<int> segmentTree(size, 0);

		init(segmentTree, 1, 0,	N - 1, arr);

		for (int i = 0; i < K; i++)
		{
			char a;
			int b, c;

			cin >> a >> b >> c;
			if (a == 'C') {
				if (arr[b - 1] == 0) {
					arr[b - 1] = c;
					init(segmentTree, 1, 0, N - 1, arr);
					continue;
				}

				if (c * arr[b - 1] > 0) updateSegment(segmentTree, 1, 0, N - 1, b - 1, 1);
				else if (c * arr[b - 1] < 0)updateSegment(segmentTree, 1, 0, N - 1, b - 1, -1);
				else updateSegment(segmentTree, 1, 0, N - 1, b - 1, 0);

				arr[b - 1] = c;
			}
			else {
				int answer = multiSegment(segmentTree, 1, b - 1, c - 1, 0, N - 1);
				if (answer > 0) cout << '+';
				else if (answer < 0) cout << '-';
				else cout << '0';
			}
		}
		cout << '\n';		
	}

}