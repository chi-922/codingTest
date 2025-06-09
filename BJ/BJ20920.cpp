#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second; // �� ��������
	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length(); // ���� ��������
	return a.first < b.first; // ������ ��������
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> freq;
	string word;
	for (int i = 0; i < N; ++i) {
		cin >> word;
		if (word.length() >= M)
			++freq[word];
	}

	vector<pair<string, int>> words(freq.begin(), freq.end());

	sort(words.begin(), words.end(), cmp);

	for (const auto& w : words) {
		cout << w.first << '\n';
	}
}
