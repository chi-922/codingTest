// Can I Win

class Solution {
public:
    int maxN;
    int target;
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxN = maxChoosableInteger;
        target = desiredTotal;

        // 전체 합이 목표보다 작으면 절대 못 이김
        int sum = maxN * (maxN + 1) / 2;
        if (sum < target) return false;

        return dfs(0, 0); // mask = 0, currentSum = 0
    }

    bool dfs(int mask, int currentSum) {
        // mask 비트 상태가 memo에 기록된 적 있는가, 있음 다시 이 케이스 안 해도 돼.
        if (memo.count(mask))
            return memo[mask];

        for (int i = 0; i < maxN; i++) {
            // (i + 1)숫자 이미 고른거면 패스
            if (mask & (1 << i)) continue;

            int pick = i + 1;  // i는 인덱스니까, 고른 숫자는 i + 1.

            // 지금 고르면 바로 이기는 경우
            if (currentSum + pick >= target)
                return memo[mask] = true;

            // 지금 패가 이길 수 있는 방법 : 어떤 상태 하나라도 상대가 지는 경우로 보낼 수 있으면 승리
            if (!dfs(mask | (1 << i), currentSum + pick))
                return memo[mask] = true;
        }

        // 그래도 이 경우(mask의 비트 상태)의 수엔 없으면 false
        return memo[mask] = false;
    }
};
