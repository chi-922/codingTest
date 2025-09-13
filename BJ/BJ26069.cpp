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
    dancers.insert("ChongChong"); // 처음 춤추는 사람

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        // a가 dancers에 있으면 b 추가
        if (dancers.find(a) != dancers.end()) {
            dancers.insert(b);
        }
        // b가 dancers에 있으면 a 추가
        else if (dancers.find(b) != dancers.end()) {
            dancers.insert(a);
        }
    }

    cout << dancers.size() << '\n';
    return 0;
}