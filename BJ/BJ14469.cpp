#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        cows.push_back({st, ed});
    }
    
    sort(cows.begin(), cows.end());
    
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time = max(cows[i].first, time);
        time += cows[i].second;
    }
    
    cout << time;
    return 0;
}
