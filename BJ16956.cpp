#include <queue>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int r, c;

string map[501];
bool flag;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	cin >> r >> c;
	queue<pair<int, int>> wolf;
    
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}
	for(int i=0; i < r; i++)
		for (int j = 0; j < c; j++)
		if (map[i][j] == 'W')
				wolf.push({ i,j });
	
	while (!wolf.empty())
	{
		int x = wolf.front().first;
		int y = wolf.front().second; 
        wolf.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (0 <= next_x && next_x < r && 0 <= next_y && next_y < c)
            {
                if (map[next_x][next_y] == '.')
                {
                    map[next_x][next_y] = 'D';

                }
                else if (map[next_x][next_y] == 'S')
                {
                    cout << 0 << '\n';
                    return 0;
                }
            }
        }
	}
	cout << 1 << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}
