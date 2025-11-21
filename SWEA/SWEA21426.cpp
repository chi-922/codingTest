#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect {
    long long x1, y1, x2, y2;
};

bool inside(const Rect& R, long long x1, long long y1, long long x2, long long y2) {
    return (R.x1 <= x1 && x2 <= R.x2 &&
        R.y1 <= y1 && y2 <= R.y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        Rect W, B1, B2;
        cin >> W.x1 >> W.y1 >> W.x2 >> W.y2;
        cin >> B1.x1 >> B1.y1 >> B1.x2 >> B1.y2;
        cin >> B2.x1 >> B2.y1 >> B2.x2 >> B2.y2;

        vector<long long> xs = { W.x1, W.x2, B1.x1, B1.x2, B2.x1, B2.x2 };
        vector<long long> ys = { W.y1, W.y2, B1.y1, B1.y2, B2.y1, B2.y2 };

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        bool visible = false;

        for (int i = 0; i < (int)xs.size() - 1; i++) {
            for (int j = 0; j < (int)ys.size() - 1; j++) {

                long long x1 = xs[i];
                long long x2 = xs[i + 1];
                long long y1 = ys[j];
                long long y2 = ys[j + 1];

                // 이 조각이 W 내부에 포함되는 조각인지
                if (!(W.x1 <= x1 && x2 <= W.x2 &&
                    W.y1 <= y1 && y2 <= W.y2))
                    continue;

                // B1 또는 B2가 이 조각을 덮는가?
                bool covered = false;
                if (inside(B1, x1, y1, x2, y2)) covered = true;
                if (inside(B2, x1, y1, x2, y2)) covered = true;

                // 덮이지 않은 조각이 존재하면 흰색 보임
                if (!covered) {
                    visible = true;
                    break;
                }
            }
            if (visible) break;
        }

        cout << (visible ? "YES\n" : "NO\n");
    }
}