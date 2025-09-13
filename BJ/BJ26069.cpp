#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    set<string> dancers;
    dancers.insert("ChongChong"); // ó�� ���ߴ� ���

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        // a�� dancers�� ������ b �߰�
        if (dancers.find(a) != dancers.end()) {
            dancers.insert(b);
        }
        // b�� dancers�� ������ a �߰�
        else if (dancers.find(b) != dancers.end()) {
            dancers.insert(a);
        }
    }

    cout << dancers.size() << '\n';
    return 0;
}