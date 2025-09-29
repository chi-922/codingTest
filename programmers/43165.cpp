// 타겟 넘버

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void combination(int num, int depth, vector<int>& numbers, int& target) {
    if(depth == numbers.size())
    {
        if(num == target) answer++;
        return;
    }
    
    for(int i = 0; i < 2; i++)
    {
        if (i == 0) combination(num + numbers[depth], depth + 1, numbers, target);
        else combination(num - numbers[depth], depth + 1, numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    combination(0, 0, numbers, target);
    return answer;
}
