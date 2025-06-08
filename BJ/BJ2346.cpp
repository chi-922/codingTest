#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<pair<int, int>> dq;
	int N, num, cur;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// 풍선에 종이, 몇번째 풍선인지 pair로 기억
		cin >> num;
		dq.push_back(make_pair(num, i + 1));
	}

	while (!dq.empty())
	{
		cur = dq.front().first;
		cout << dq.front().second << " ";
		dq.pop_front();

		if (dq.empty()) break;

		if (cur > 0) {
			for (int i = 0; i < cur - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < -cur; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}