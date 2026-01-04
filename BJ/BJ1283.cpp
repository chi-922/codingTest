#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<char> alpha;

void solve(string& s) {
	int idx = -1;
	bool flag = true;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i - 1] == ' ') {
			if (alpha.find(s[i]) == alpha.end()) {
				flag = false;
				char temp = toupper(s[i]);
				alpha.insert(temp);
				alpha.insert(temp + 32);

				idx = i;
				break;
			}
		}
	}

	for (int i = 0; i < s.size(); i++) {
		if (flag) {
			if (s[i] == 32) {
				cout << s[i];
			}
			else if (alpha.find(s[i]) == alpha.end()) {
				// 알파벳 못 찾으면 단축키
				// 하나만 하고 넘어가야해
				flag = false;
				char temp = toupper(s[i]);
				alpha.insert(temp);
				alpha.insert(temp + 32);
				cout << '[' << s[i] << ']';
			}
			else {
				cout << s[i];
			}
		}
		else {
			if (i == idx) {
				cout << '[' << s[i] << ']';
			}
			else {
				cout << s[i];
			}
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);

		solve(str);
	}
}