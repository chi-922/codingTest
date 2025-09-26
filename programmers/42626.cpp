#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    while(true)
    {
        if(pq.top() >= K) break;
        if(pq.size() == 1 && pq.top() < K)
        {
            answer = -1;
            break;
        }

        int firstFood = pq.top();
        pq.pop();
        int secondFood = pq.top();
        pq.pop();

        pq.push(firstFood + (secondFood * 2));
        answer++;
    }


    return answer;
}
