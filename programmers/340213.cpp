// 비디오 재생기

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int toSec(const string& timeStr) {
    int minutes = stoi(timeStr.substr(0, 2));
    int seconds = stoi(timeStr.substr(3, 2));
    return minutes * 60 + seconds;
}

string toStr(int sec) {
    int minutes = sec / 60;
    int seconds = sec % 60;

    string minStr = (minutes < 10 ? "0" : "") + to_string(minutes);
    string secStr = (seconds < 10 ? "0" : "") + to_string(seconds);

    return minStr + ":" + secStr;
}

string solution(string videoLen, string pos,
                string opStart, string opEnd,
                const vector<string>& commands) {

    int now = toSec(pos);
    int end = toSec(videoLen);
    int opStartSec = toSec(opStart);
    int opEndSec = toSec(opEnd);

    auto normalize = [&](int current) {
        if (current < 0) current = 0;
        else if (current > end) current = end;

        if (opStartSec <= current && current <= opEndSec) {
            current = opEndSec;
        }
        return current;
    };

    now = normalize(now);

    for (const string& command : commands) {
        if (command == "next") {
            now += 10;
        } 
        else if (command == "prev") {
            now -= 10;
        }

        now = normalize(now);
    }

    return toStr(now);
}
