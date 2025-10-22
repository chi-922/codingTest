// 2개 이하로 다른 비트

#include <string>
#include <vector>

using namespace std;

long long bitmask (long long num) {
    // 짝수면 바로 +1 한 게 답
    if (num % 2 == 0) return num + 1;
    
    // 오른쪽에서 처음 등장하는 0의 자리 (2^k)
    long long number = ~num & (num + 1);
    
    return (number >> 1) + num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(bitmask(numbers[i]));
    }
    return answer;
}
