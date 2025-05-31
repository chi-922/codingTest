#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	string temp;
	vector<string> name;
	unordered_map<string, int> poketmon;

	cin >> n >> m;
	name.resize(n + 1);  // 1-based index ����

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		name[i] = temp;                // 1-based �ε���
		poketmon[temp] = i;            // �̸� �� ��ȣ
	}

	// ���� Ǯ��
	for (int i = 0; i < m; i++)
	{
		cin >> temp;

		if (isdigit(temp[0])) {
			// ���ڷ� ���� �� �ε���
			cout << name[stoi(temp)] << '\n';
		}
		else {
			// ���ڿ� �� ��ȣ
			cout << poketmon[temp] << '\n';
		}
	}
}