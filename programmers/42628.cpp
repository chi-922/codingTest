// 42628. 이중우선순위큐

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    multiset<int> pq;

    for(string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            pq.insert(num);
        } else if (op[0] == 'D' && pq.size()) {
            if (op[2] == '-') pq.erase(pq.begin());
            else pq.erase(--pq.end());
        }
    }

    if (pq.empty()) return {0, 0};
    return {*--pq.end(), *pq.begin()};
}
