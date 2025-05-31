#include <iostream>
#include <string>

using namespace std;

bool contain666(int n) {
	string sNum = to_string(n);
	return sNum.find("666") != string::npos;
}

int main() {
	int series;
	int cnt = 0;
	int check = 665;

	cin >> series;

	while (cnt < series)
	{
		check++;
		if (contain666(check)) {
			cnt++;
		}
	}

	cout << check << endl;
}