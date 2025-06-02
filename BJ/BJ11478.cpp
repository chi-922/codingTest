#include <string>
#include <set>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	set<string> pocket;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i; j < str.length(); j++) {
			pocket.insert(str.substr(i, j - i + 1));
		}
	}

	cout << pocket.size();
}