#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	stack<int> st;
	string action;
	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> action;

		if (action == "push") {
			cin >> num;
			st.push(num);
		}
		else if (action == "pop") {
			if (st.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (action == "size") {
			cout << st.size() << endl;
		}
		else if (action == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (action == "top") {
			if (st.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << st.top() << endl;
			}
		}
	}

	return 0;
}