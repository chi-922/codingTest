// 연속된 수열의 합

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};
    int st = 0, ed = 0;
    int sum = 0;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        sum += sequence[st++];

        if(sum > k)
            while(sum - sequence[ed] >= k)
                sum -= sequence[ed++];
        if(sum == k)
            if(answer[1] - answer[0] > st - 1 - ed)
                answer = { ed, st - 1 };
    }
    
    return answer;
}
