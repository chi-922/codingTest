// 이웃한 칸

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    string now = board[h][w];
    
    for(int d = 0; d < 4; d++) {
        int nr = h + dr[d];
        int nc = w + dc[d];
        
        if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()) continue;
        if (board[nr][nc] == now) answer++;
    }
    return answer;
}
