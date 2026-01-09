#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, T;
bool possible = false;

void dfs(string cur) {
    if (possible) return;

    if (cur.length() == S.length()) {
        if (cur == S) possible = true;
        return;
    }

    // 뒤가 A면 제거
    if (!cur.empty() && cur.back() == 'A') {
        string next = cur;
        next.pop_back();
        dfs(next);
    }

    // 앞이 B면 제거 후 뒤집기
    if (!cur.empty() && cur.front() == 'B') {
        string next = cur.substr(1);
        reverse(next.begin(), next.end());
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> T;

    dfs(T);

    cout << (possible ? 1 : 0);
    return 0;
}
