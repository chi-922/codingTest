#include <iostream>
#include <vector>

using namespace std;

int joon(int money, vector<int>& chart) {
	int stock = 0;
	for (int price : chart) {
		stock += money / price;
		money %= price;
	}

	return money + (stock * chart[13]);
}

int sung(int money, vector<int>& chart) {
	int stock = 0;
	int transition = 0;
	for (int i = 1; i < 14; i++) {
		if (chart[i] > chart[i - 1]) {
			if (transition < 0) transition = 0;
			transition++;
		}
		else if (chart[i] < chart[i - 1]) {
			if (transition > 0) transition = 0;
			transition--;
		}
		else if (chart[i] == chart[i - 1]) transition = 0;

		if (transition == 3) {
			money += stock * chart[i];
			stock = 0;
			transition = 0;
		}
		else if (transition <= -3) {
			stock += money / chart[i];
			money %= chart[i];
		}
	}

	return money + (stock * chart[13]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int money;
	vector<int> chart(14, 0);

	cin >> money;
	for (int i = 0; i < 14; i++) cin >> chart[i];

	int hyeon = joon(money, chart);
	int min = sung(money, chart);

	if (hyeon > min) cout << "BNP";
	else if (hyeon < min) cout << "TIMING";
	else cout << "SAMESAME";
}