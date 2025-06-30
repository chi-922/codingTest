#include <iostream>
#include <queue>

using namespace std;

int N, temp;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> temp;
	pq.push(temp);

	for (int i = 1; i < N * N; i++)
	{
		cin >> temp;
		pq.push(temp);

		if (pq.size() > N) {
			pq.pop();
		}
	}

	cout << pq.top();
}