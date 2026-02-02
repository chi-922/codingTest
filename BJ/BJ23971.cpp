#include <vector>
#include <iostream>

using namespace std;

int h, w, n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w >> n >> m;

	int answer = 0;

	for (int i = 0; i < h; i += n + 1)
	{
		for (int j = 0; j < w; j += m + 1)
		{
			answer++;
		}
	}

	cout << answer;
}