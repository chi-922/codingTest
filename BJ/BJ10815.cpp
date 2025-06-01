#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> card;
int temp;

int bianarySearch(int* question, int* N) {
	int start = 0;
	int end = *N - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (card[mid] == *question) {
			return 1;
		}

		if (card[mid] < *question) {
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		card.push_back(temp);
	}

	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; i++
		)
	{
		cin >> temp;
		cout << bianarySearch(&temp, &N) << " ";
	}
}