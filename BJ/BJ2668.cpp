#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
vector<bool> visited, finished, inCycle;

void dfs(int cur) {
    visited[cur] = true;
    int next = arr[cur];

    if (!visited[next]) {
        dfs(next);
    }
    else if (!finished[next]) {
        // 사이클 발견
        int temp = next;
        while (temp != cur) {
            inCycle[temp] = true;
            temp = arr[temp];
        }
        inCycle[cur] = true;
    }

    finished[cur] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n + 1);
    visited.assign(n + 1, false);
    finished.assign(n + 1, false);
    inCycle.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (inCycle[i]) result.push_back(i);
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int x : result) {
        cout << x << '\n';
    }
}