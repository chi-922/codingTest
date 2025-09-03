#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib> // std::abs

using namespace std;

int N, M;
vector<pair<int, int>> homes;
vector<pair<int, int>> chickens;
vector<bool> visited;
int best = numeric_limits<int>::max();

void dfs(int idx, int cnt) {
    if (cnt == M) {
        int total = 0;
        for (const auto& h : homes) {
            int md = numeric_limits<int>::max();
            for (int j = 0; j < (int)chickens.size(); ++j) {
                if (visited[j]) {
                    int d = abs(h.first - chickens[j].first) + abs(h.second - chickens[j].second);
                    md = min(md, d);
                }
            }
            total += md;
            if (total >= best) break; // 가지치기
        }
        best = min(best, total);
        return;
    }

    for (int i = idx; i < (int)chickens.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x; cin >> x;
            if (x == 1) homes.push_back({ i, j });
            else if (x == 2) chickens.push_back({ i, j });
        }
    }

    visited.assign(chickens.size(), false);
    dfs(0, 0);

    cout << best << '\n';
    return 0;
}
