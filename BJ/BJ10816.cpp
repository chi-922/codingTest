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

	// ���� Ž���� �����ϱ� ���� ������ �������� ����
	sort(mine.begin(), mine.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		// upper : n���� ū�� ù��° ��ġ, lower : n�� ������ ù��° ��ġ
		cout << upper_bound(mine.begin(), mine.end(), num) - lower_bound(mine.begin(), mine.end(), num) << ' ';
	}

}