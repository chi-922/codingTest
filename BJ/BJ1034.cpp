#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> rows;
    rows.reserve(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        rows.push_back(s);
    }

    int k;
    cin >> k;

    unordered_map<string, int> freq;

    for (int i = 0; i < n; i++) {
        string pattern = rows[i];
        freq[pattern] = freq[pattern] + 1;
    }

    int answer = 0;

    for (const pair<const string, int>& item : freq) {
        string pattern = item.first;
        int count = item.second;

        int zeroCount = 0;
        for (int i = 0; i < (int)pattern.size(); i++) {
            if (pattern[i] == '0') {
                zeroCount++;
            }
        }

        bool ok1 = (zeroCount <= k);
        bool ok2 = ((k - zeroCount) % 2 == 0);

        if (ok1 && ok2) {
            answer = max(answer, count);
        }
    }

    cout << answer;
    return 0;
}
