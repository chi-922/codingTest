#include <iostream>
#include <vector>

#define INF 10e12

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<long long> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

    long long left = 0, right = 0;
    long long sum = 0;
    long long ans = INF;

    while (left <= right)
    {
        if (sum >= s)
        {
            ans = min(ans, right - left);
            sum -= arr[left];
            left++;
        }
        else if (right == n) break;
        else
        {
            sum += arr[right];
            right++;
        }
    }
    if (ans == INF) cout << 0;
    else cout << ans;

}