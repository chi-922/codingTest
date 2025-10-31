#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int h = (n % w) ? (n / w + 1) : (n / w);
    vector<vector<int>> box(h, vector<int>(w, 0));
    
    int cnt = 1;
    int num_r = 0, num_c = 0;
    for (int i = 0; i < h; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < w; j++)
            {   
                if (cnt <= n)
                {
                    if (cnt == num) {
                        num_r = i;
                        num_c = j;
                    }
                    box[i][j] = cnt;
                    cnt++;
                } else {
                    box[i][j] = 0;
                }

            }
        } else {
            for (int j = w - 1; j >= 0; j--)
            {   
                if (cnt <= n)
                {
                    if (cnt == num) {
                        num_r = i;
                        num_c = j;
                    }
                    box[i][j] = cnt;
                    cnt++;
                } else {
                    box[i][j] = 0;
                }

            }
        }
    }

    int answer = 0;
    if (box[h - 1][num_c] == 0) answer = h - 1 - num_r;
    else answer = h - num_r;

    return answer;
}
