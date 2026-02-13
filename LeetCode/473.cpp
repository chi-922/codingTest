// Matchsticks to Square

class Solution {
public:
    vector<bool> used;

    bool makesquare(vector<int>& matchsticks) {
        // 4개 이상 안 들어있음 정사각형 만들지도 못 함.
        if (matchsticks.size() < 4) return false;

        int sum = 0;
        for (const int& m : matchsticks) {
            sum += m;
        }

        // 4의 배수 아님 거르기 먼저
        if (sum % 4 != 0) return false;

        // 한변의 길이
        int line = sum / 4;

        // 비트마스크로 line 값 맞춰가기
        used.resize(matchsticks.size(), false);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, line, 0, 0);
    }

    bool dfs(vector<int>& matchsticks, int& line, int subsum, int depth) {
        if (depth == 3) return true;

        for (int i = 0; i < (int)matchsticks.size(); i++) {
            if (used[i]) continue;

            int temp = subsum + matchsticks[i];
            if (temp > line) continue;

            used[i] = true;

            if (temp == line) {
                if (dfs(matchsticks, line, 0, depth + 1)) return true;
            } else {
                if (dfs(matchsticks, line, temp, depth)) return true;
            }

            used[i] = false;

            // 가지치기: 새 변의 첫 조각이 실패하면 다른 조각도 대부분 의미 없음(대칭 제거)
            if (subsum == 0) break;

            // 가지치기: 같은 길이 막대는 같은 결과 -> 중복 시도 방지
            while (i + 1 < (int)matchsticks.size() && matchsticks[i + 1] == matchsticks[i]) i++;
        }

        return false;
    }
};
