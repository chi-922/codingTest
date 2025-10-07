// 퍼즐 게임 챌린지

#include <string>
#include <vector>

using namespace std;


long long puzzle (int level, vector<int>& diffs, vector<int>& times) {
    long long time = 0;
    for (int i = 0; i < diffs.size(); i++)
    {
        if (level >= diffs[i]) time += times[i];
        else
        {
            int cnt = diffs[i] - level;
            time += (times[i] + times[i - 1]) * cnt + times[i];
        }
    }
    return time;
}

int binarySearch(int a, int b, vector<int>& diffs, vector<int>& times, long long& limit) {
    if (a > b) return a; // 종료 조건
    
    int mid = (a + b) / 2;
    long long time = puzzle(mid, diffs, times);

    if (time > limit) return binarySearch(mid + 1, b, diffs, times, limit);
    else if (time < limit) return binarySearch(a, mid - 1, diffs, times, limit);
    else return mid;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int minv = 100000, maxv = 1;
    for (int i = 0; i < diffs.size(); i++)
    {
        if (diffs[i] > maxv) maxv = diffs[i];
        if (diffs[i] < minv) minv = diffs[i];
    }
    
    int answer = binarySearch(minv, maxv, diffs, times, limit);
    return answer;
}
