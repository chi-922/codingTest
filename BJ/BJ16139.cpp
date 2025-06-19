#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	char alpha;
	int q, l, r;
	vector<vector<int>> arr;

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;

	arr.resize(27, vector<int>(str.length() + 1, 0));

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < 27; j++)
		{
			if (str[i] - 97 == j) {
				arr[j][i + 1] = arr[j][i] + 1;
			}
			else {
				arr[j][i + 1] = arr[j][i];
			}
		}
	}

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> alpha >> l >> r;
		cout << arr[alpha - 97][r + 1] - arr[alpha - 97][l] << '\n';

	}
}