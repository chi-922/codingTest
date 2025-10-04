#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    pair<int, string> tmp;
    vector<pair<int, string>> arr;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}