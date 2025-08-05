#include <iostream>
using namespace std;

int calcRate(long long x, long long y) {
    return (100 * y) / x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, z;
    int count = -1;

    cin >> x >> y;

    z = calcRate(x, y);

    if (z >= 99) {
        cout << count << endl;
        return 0;
    }

    int left = 0;
    int right = 1000000000;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        long long newz = calcRate(x + mid, y + mid);

        if (z < newz) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}