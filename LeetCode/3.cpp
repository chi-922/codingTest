// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();

        unordered_map<char, int> m;  // 이 알파벳은 몇번째에 있는가

        /*
        한 번 s 훑으면서 m에 index 업데이트 해주기.
        어떤 알파벳이든 st 이후로 재등장 하면 (=이미 m에 기록되어 있다면) 그 index - st - 1 이 최종길이.
        그리고 st는 재등장 하기 전에 기록되어있던 숫자 + 1 부터 다시 확인
        */
        int st = 0;
        int answer = 1;
        for (int i = 0; i < s.length(); i++) {
            // 지금 보고있는 알파벳이 이미 m에 있다면
            if (m.find(s[i]) != m.end() && m[s[i]] >= st) {
                answer = max(answer, i - st);
                st = m[s[i]] + 1;
                m[s[i]] = i;
            } else {
                m[s[i]] = i;
            }
            // 마지막 쪽에서 쭉 겹치는 거 없이 끝나는 경우 있을 수 있으니 체크
            if (i == s.length() - 1) answer = max(answer, i - st + 1);
        }


        return answer;
    }
};
