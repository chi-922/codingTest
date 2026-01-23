#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> down, up;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    
    int min = 500000, cnt = 0;
    cin >> n >> h;

    for(int i = 0 ; i < n / 2; i++) {
        int a, b;
        cin >> a >> b;
        down.push_back(a);
        up.push_back(b);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    vector<int> ans(h);
   
    for(int i = 1 ; i <= h ; i++) {
        // lower_bound: value 값 보다 크거나 같은 첫 번째 원소의 주소
        int downIdx = lower_bound(down.begin(), down.end(), i) - down.begin();
        // upper_bound: 처음으로 value 값을 초과하는 원소의 주소
        int upIdx = lower_bound(up.begin(), up.end(), h - i + 1) - up.begin();
        
        // 높이 i일 때 몇 개의 장애물을 파괴하는지
        int cur = n - (downIdx + upIdx);
        
        if(cur < min) {
            min = cur;
            cnt = 1;
        }
        else if(cur == min) cnt++;
    }

    cout << min << " " << cnt;

    return 0;
}
