#include <iostream>

using namespace std;

long long arr[50] = {0,1,};

long long fibo(int n)
{
    if(n == 0 || n == 1) return arr[n];
    else if(arr[n] == 0) arr[n] = fibo(n - 1) + fibo(n - 2);
    return arr[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    int tmp;
    for(int i = 0; i < T; i++)
    {
        cin >> tmp;
        if(tmp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibo(tmp-1) << ' ' << fibo(tmp) << '\n';
    }
}
