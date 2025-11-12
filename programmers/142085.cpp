// 디펜스 게임

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;
    int knight = n;
    int chance = k;
    
    while(answer < enemy.size())
    {
        int turn = enemy[answer];
        if (knight >= turn)
        {
            knight -= turn;
            pq.push(turn);
            answer++;
        }
        else if (chance > 0)
        {
            if (!pq.empty() && pq.top() > turn)
            {
                knight += pq.top();
                pq.pop();
                chance--;
            } else {
                chance--;
                answer++;
            }
        } else break;
    }
    
    return answer;
}
