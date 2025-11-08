// 롤케이크 자르기

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> chulsoo;
    map<int, int> brother;
    for (int& i : topping) {
        brother[i]++;
    }
    for (int i = 0; i < topping.size() - 1; i++) {
        chulsoo[topping[i]]++;
        brother[topping[i]]--;
        if (brother[topping[i]] == 0) {
            brother.erase(topping[i]);
        }
        if (chulsoo.size() == brother.size()) answer++;
    }
    return answer;
}
