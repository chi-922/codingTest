#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<string> listen;
	set<string> see;
	vector<string> result;
	int N, M;
	string temp;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		listen.insert(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		see.insert(temp);
	}

	set_intersection(listen.begin(), listen.end(), see.begin(), see.end(), back_inserter(result));

	cout << result.size() << endl;
	for (string str : result)
	{
		cout << str << endl;
	}
}