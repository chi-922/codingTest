// 같은 숫자는 싫어

#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> s;
    
    int bf = -1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (bf != arr[i]) s.push(arr[i]);
        bf = arr[i];
    }
    
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        answer.push_back(temp);
    }
    
    return answer;
}
