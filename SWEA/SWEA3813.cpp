#include <iostream>
#include <vector>

using namespace std;

static const int MAX_WEAR = 200000;

int N, K;
vector<int> w;
vector<int> s;

bool isPossible(int mid) {
    int cnt = 0;   // 현재 연속 블록 길이 (w[i] <= mid)
    int idx = 1;   // s[idx]를 만족해야 하는 현재 구간 인덱스(1..K)

    for (int i = 1; i <= N; ++i) {
        if (w[i] <= mid) {
            ++cnt;
        }
        else {
            cnt = 0;
        }

        // s[idx] 개만큼 연속 블록을 확보했다면 다음 구간으로
        if (idx <= K && cnt == s[idx]) {
            ++idx;
            cnt = 0;
            if (idx > K) return true; // K개 모두 확보
        }
    }
    return false;
}

void runTest(int tc) {
    int low = 1;
    int high = MAX_WEAR;
    int answer = MAX_WEAR;

    // Parametric Search (최소 가능한 wear level)
    while (low < high) {
        int mid = (low + high) / 2;

        if (isPossible(mid)) {
            high = mid;
            answer = high;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "#" << tc << " " << answer << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> K;

        w.assign(N + 1, 0);
        s.assign(K + 1, 0);

        for (int i = 1; i <= N; ++i) cin >> w[i];
        for (int i = 1; i <= K; ++i) cin >> s[i];

        runTest(tc);
    }
    return 0;
}
