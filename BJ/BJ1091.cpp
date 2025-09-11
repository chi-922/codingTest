#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; ++i) cin >> p[i];  // 목표 소유자 (0/1/2)
    for (int i = 0; i < n; ++i) cin >> s[i];  // 섞기

    // 초기 상태: 각 위치의 소유자
    vector<int> init(n), cur(n);
    for (int i = 0; i < n; ++i) init[i] = i % 3;
    cur = init;

    if (cur == p) { cout << 0; return 0; }

    int cnt = 0;
    while (true) {
        vector<int> nxt(n);
        // i번 위치로 s[i]에서 가져옴
        for (int i = 0; i < n; ++i) nxt[i] = cur[s[i]];

        cur.swap(nxt);
        ++cnt;

        if (cur == p) { cout << cnt; return 0; }
        if (cur == init) { cout << -1; return 0; } // 사이클 복귀
    }
}
