#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Mat;

const int MOD=1000;

int n;

// Mat 타입(행렬)끼리 곱하기 * 연산자를 사용하게 되면 아래의 함수가 실행
Mat operator*(const Mat& a, const Mat& b)
{
    // 똑같이 빈 행렬 준비해두고
    Mat ret(n, vector<int>(n, 0));
  
    for (int i = 0;i < n; ++i)
        for (int j = 0;j < n; ++j)
        {
            for (int k = 0;k < n; ++k)
                ret[i][j] += a[i][k] * b[k][j];
            ret[i][j] %= MOD;
        }
    return ret;
}

// 행렬의 거듭 제곱
Mat pow(const Mat& mat, long long p)
{
    // 기저 사례: 항등 행렬 반환
    if(p == 0)
    {
        Mat temp(n, vector<int>(n));
        for(int i = 0; i < n; ++i)
            temp[i][i] = 1;
        return temp;
    }

  // 홀수면 p/2 * p/2 + 1 하려고
    if(p & 1)
        return mat * pow(mat, p - 1);
  
    Mat half = pow(mat, p / 2);
    return half * half;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
    long long p;
    cin >> n >> p;
    
    Mat mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    
    Mat ret = pow(mat, p);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << ret[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
