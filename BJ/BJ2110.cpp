#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> house;

bool installable(int dist) {
    int cnt = 1;
    int last = house[0];

    for (int i = 1; i < n; i++) {
        if (house[i] - last >= dist) {
            cnt++;
            last = house[i];
        }
    }
    return cnt >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    house.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    // 설치 거리 기준으로 이분탐색, 두 집 사이의 거리는 어쨋거든 최소 1.
    int left = 1;
    int right = house[n - 1] - house[0];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (installable(mid)) {
            answer = mid;
            left = mid + 1; // 더 큰 거리 시도
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
