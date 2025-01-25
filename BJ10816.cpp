#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> mine;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		mine.push_back(num);
	}

	// 이진 탐색을 수행하기 위해 데이터 오름차순 정렬
	sort(mine.begin(), mine.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		// upper : n보다 큰거 첫번째 위치, lower : n이 나오는 첫번째 위치
		cout << upper_bound(mine.begin(), mine.end(), num) - lower_bound(mine.begin(), mine.end(), num) << ' ';
	}

}