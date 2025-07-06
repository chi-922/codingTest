#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visited[100001] = { 0, };
int ans = 0;
int minCnt = 2147483647;

void bfs() {
    queue<pair<int, int>> q;
    q.push({ n, 0 });
    visited[n] = 1;

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == k) {
            if (cnt < minCnt) {
                minCnt = cnt;
                ans = 1;
            }
            else if (cnt == minCnt) {
                ans++;
            }
            continue;
        }

        // 세 방향 모두 검사
        int nextArr[3] = { now - 1, now + 1, now * 2 };
        for (int i = 0; i < 3; i++) {
            int next = nextArr[i];
            if (next >= 0 && next <= 100000) {
                if (!visited[next] || visited[next] == cnt + 1) {
                    q.push({ next, cnt + 1 });
                    visited[next] = cnt + 1;
                }
            }
        }
    }

    cout << minCnt << '\n' << ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	bfs();
}