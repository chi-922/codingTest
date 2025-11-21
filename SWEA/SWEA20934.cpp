#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        string user;
        int K;
        cin >> user >> K;

        int pos = user.find('o'); // o 위치 찾기

        if (K == 0) {
            cout << "#" << i + 1 << " " << pos << '\n';
        }
        else if (pos == 0) {
            if (K % 2 == 0)
                cout << "#" << i + 1 << " 0\n";
            else
                cout << "#" << i + 1 << " 1\n";
        }
        else if (pos == 1) {
            if (K % 2 == 0)
                cout << "#" << i + 1 << " 1\n";
            else
                cout << "#" << i + 1 << " 0\n";
        }
        else if (pos == 2) {
            if (K % 2 == 0)
                cout << "#" << i + 1 << " 0\n";
            else
                cout << "#" << i + 1 << " 1\n";
        }
    }

    return 0;
}
