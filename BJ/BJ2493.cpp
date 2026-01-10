#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<pair<int, int>> s;
	
	for (int i = 1; i <= n; i++) {
		int tower;
		cin >> tower;
		
		while (!s.empty()) {
			// top이 현재 타워보다 크다면 신호를 받을 수 있다
			if (s.top().second > tower) {
				cout << s.top().first << ' ';
				break;
			}
			// 작으면 pop
			s.pop();
		}
		
		if (s.empty()) {
			cout << '0' << ' ';
		}
		
		s.push(make_pair(i, tower));
	}
	
	return 0;
}
