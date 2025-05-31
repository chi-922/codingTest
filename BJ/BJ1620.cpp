#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	string temp;
	vector<string> name;
	unordered_map<string, int> poketmon;

	cin >> n >> m;
	name.resize(n + 1);  // 1-based index 대응

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		name[i] = temp;                // 1-based 인덱스
		poketmon[temp] = i;            // 이름 → 번호
	}

	// 문제 풀이
	for (int i = 0; i < m; i++)
	{
		cin >> temp;

		if (isdigit(temp[0])) {
			// 숫자로 시작 → 인덱스
			cout << name[stoi(temp)] << '\n';
		}
		else {
			// 문자열 → 번호
			cout << poketmon[temp] << '\n';
		}
	}
}