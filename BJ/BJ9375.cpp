#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 1; i < tc + 1; i++)
	{
		map<string, set<string>> clothes;
		
		int cloth;
		cin >> cloth;

		for (int j = 0; j < cloth; j++)
		{
			string name, kind;
			cin >> name >> kind;
			if (clothes.find(kind) != clothes.end()) {
				clothes[kind].insert(name);
			}
			else {
				clothes.insert({ kind, {name} });
			}
		}

		int answer = 1;
		for (auto& temp: clothes)
		{
			answer *= (temp.second.size() + 1);
		}

		cout << answer - 1 << '\n';
	}
}