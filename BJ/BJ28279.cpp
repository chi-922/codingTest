#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int N, action, temp;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> action;
		if (action == 1) {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (action == 2) {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (action == 3) {
			if (dq.empty()) {
				cout << -1 << endl;
			} else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (action == 4) {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (action == 5) {
			cout << dq.size() << endl;
		}
		else if (action == 6) {
			if (dq.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (action == 7) {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.front() << endl;
			}
		}
		else if (action == 8) {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
	}
}