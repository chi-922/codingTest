#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num;
	double kim, im;
	cin >> num >> kim >> im;

	int round = 0;

	while (kim != im) {
		//김지민과 임한수의 번호가 같아질때 까지 반복
		kim = ceil(kim / 2);
		im = ceil(im / 2);
		round++;
	}

	cout << round;

	return 0;
}