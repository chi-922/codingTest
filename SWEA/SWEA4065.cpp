#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	vector<vector<int>> dna;

	for (int tc = 1; tc < T + 1; tc++)
	{
		string str1, str2;
		cin >> str1 >> str2;

		dna.assign(str1.size() + 1, vector<int>(str2.size() + 1, 0));

		for (int i = 1; i < str1.size() + 1; i++)
		{
			for (int j = 1; j < str2.size() + 1; j++)
			{
				if (str1[i - 1] == str2[j - 1]) dna[i][j] = dna[i - 1][j - 1] + 1;
				else dna[i][j] = max(dna[i - 1][j], dna[i][j - 1]);
			}
		}

		cout << '#' << tc << ' ' << dna[str1.size()][str2.size()] << '\n';
	}
}