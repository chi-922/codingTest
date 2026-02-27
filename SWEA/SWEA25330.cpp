#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	(void)freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	while (tc--)
	{
		map<int, vector<int>> m;   // 숫자 : 그 숫자 나오는 인덱스
		string num;
		cin >> num;

		for (int i = 0; i < num.length(); i++)
		{
			int intn = num[i] - '0';
			m[intn].push_back(i);
		}

		bool isok = true;
		for (const auto& pair : m) {
			if (pair.second.size() != 2) {
				isok = false;
				break;
			}
			if (pair.second[1] - pair.second[0] - 1 != pair.first) {
				isok = false;
				break;
			}
		}

		if (isok) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}