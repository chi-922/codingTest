// 대충 만든 자판

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    map<char, int> keyboard;
    
    for (char i = 'A'; i <= 'Z'; i++) {
        keyboard.insert({i, 101});
    }
    for (char i = 'a'; i <= 'z'; i++) {
        keyboard.insert({i, 101});
    }
    
    for (const string& item: keymap) {
        for (int i = 0; i < item.size(); i++) {
            if (i + 1 < keyboard[item[i]]) keyboard[item[i]] = i + 1;
        }
    }
    
    vector<int> answer(targets.size(), 0);
    
    for (int i = 0; i < targets.size(); i++) {
        string target = targets[i];
        int sum = 0;
        for (char& ch : target) {
            if (keyboard[ch] == 101) {
                sum = -1;
                break;
            }
            sum += keyboard[ch];
        }
        answer[i] = sum;
    }
    
    return answer;
}
