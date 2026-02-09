// Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int ss = s.length();

        int sero = 1;
        while(true) {
            if (ss - 1 < 2 * sero * (numRows - 1)) break;
            else sero++;
        }

        // sero의 왼쪽 편까지 확인 필수
        string answer = "";
        int r = 0;
        while(r < numRows) {
            if (r == 0) {
                for (int i = 0; i < sero; i++) {
                    answer += s[2 * i * (numRows - 1)];
                }
            }
            else if (r == numRows - 1) {
                for (int i = 0; i <= sero; i++) {
                    if ((2 * i + 1) * (numRows - 1) > ss - 1) continue;
                    answer += s[(2 * i + 1) * (numRows - 1)];
                }
            }
            else {
                if (r <= ss - 1) answer += s[r];
                for (int i = 1; i <= sero; i++) {
                    if (2 * i * (numRows - 1) - r > ss - 1) continue;
                    answer += s[2 * i * (numRows - 1) - r];
                    if (2 * i * (numRows - 1) + r > ss - 1) continue;
                    answer += s[2 * i * (numRows - 1) + r];
                }
            }
            r++;
        }

        return answer;
    }
};

/* chatgpt refactory */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        int dir = 1; // 1: down, -1: up

        for (char c : s) {
            rows[currentRow] += c;

            // 방향 전환
            if (currentRow == 0)
                dir = 1;
            else if (currentRow == numRows - 1)
                dir = -1;

            currentRow += dir;
        }

        string answer;
        for (const string& row : rows)
            answer += row;

        return answer;
    }
};
