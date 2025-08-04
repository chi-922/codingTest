#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int n;
vector<vector<int>> tree(26, vector<int>(2, -1));

void preOrder(int t) {
	if (t != -1) {
		cout << static_cast<char>(t + 'A');
		preOrder(tree[t][0]);
		preOrder(tree[t][1]);
	}
}

void inOrder(int t) {
	if (t != -1) {
		inOrder(tree[t][0]);
		cout << static_cast<char>(t + 'A');
		inOrder(tree[t][1]);
	}
}

void postOrder(int t) {
	if (t != -1) {
		postOrder(tree[t][0]);
		postOrder(tree[t][1]);
		cout << static_cast<char>(t + 'A');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.') tree[p - 'A'][0] = l - 'A';
		if (r != '.') tree[p - 'A'][1] = r - 'A';
	}

	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
}