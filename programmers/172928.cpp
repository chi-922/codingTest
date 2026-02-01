// 공원 산책

#include <string>
#include <map>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

map<char, int> mapping = {
    {'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}
};

vector<int> solution(vector<string> park, vector<string> routes) {
    int cr, cc;
    for (int i = 0; i < park.size(); ++i) {
        for (int j = 0; j < park[i].size(); ++j) {
            if (park[i][j] == 'S') {
                cr = i; cc = j;
                break;
            }
        }
    }

    for (int i = 0; i < routes.size(); ++i) {
        int dir = mapping[routes[i][0]];
        int num = routes[i][2] - '0';

        int nr = cr, nc = cc;
        while (num--) {
            nr += dr[dir];
            nc += dc[dir];

            if (nr < 0 || nr >= park.size() || nc < 0 || nc >= park[0].size()) break;
            if (park[nr][nc] == 'X') break;
        }

        if (num < 0) {
            cr = nr;
            cc = nc;
        }
    }
    
    return {cr, cc};
}
