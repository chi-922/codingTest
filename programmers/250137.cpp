// 붕대 감기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int sec = 1, numOfAttack = 0, seq = 0;
    int n = attacks.size();
    bool death = false;
    
    while (sec <= attacks[n - 1][0])
    {
        if (sec == attacks[numOfAttack][0]) {
            seq = 0;
            answer -= attacks[numOfAttack][1];
            numOfAttack++;
            if (answer <= 0) {
                death = true;
                break;
            }
        } else {
            seq += 1;
            answer += bandage[1];
            if (seq == bandage[0]) {
                answer += bandage[2];
                seq = 0;
            }
            if (answer > health) answer = health;
        }
        sec++;
    }
    
    if (death) return -1;
    else return answer;
}
