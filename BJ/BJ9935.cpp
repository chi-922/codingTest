#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word, boom;
    cin >> word >> boom;
    int bsize = boom.size();

    string result;
    result.reserve(word.size()); // 미리 용량 확보

    for (char c : word) {
        result.push_back(c);

        // 뒤쪽이 boom과 같으면 제거
        if (result.size() >= bsize) {
            bool match = true;
            for (int i = 0; i < bsize; ++i) {
                if (result[result.size() - bsize + i] != boom[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.erase(result.size() - bsize, bsize);
            }
        }
    }

    if (result.empty()) cout << "FRULA";
    else cout << result;
    return 0;
}
