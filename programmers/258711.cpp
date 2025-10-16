// 도넛과 막대 그래프

#include <string>
#include <vector>
#include <queue>

using namespace std;  
  
int inde[1000001];
int outde[1000001];  
vector<vector<int>> path(1000001);  
int shapeInfinite = 0,shapeOne = 0,shapeDonut = 0;  
  
void check(int start){  
	queue<int> q;
	q.push(start);
    
	bool isvisted = false;   //시작점을 방문 했는지
	while(!q.empty()){
		int now = q.front();
		q.pop();
        
		if(now == start && isvisted){  
			shapeDonut++;  
			return;  
		}  
  
		if(path[now].size() >= 2){  
			shapeInfinite++;  
			return;  
		}  
  
		for(int i = 0; i < path[now].size(); i++){  
			q.push(path[now][i]);  
		}	  
		isvisted = true;  
	}  
	shapeOne++;  
	return;  
}  
  
  
vector<int> solution(vector<vector<int>> edges) {  
	vector<int> answer;  
  
	for(int i = 0; i < edges.size(); i++){  
        // edges[i] 0에서 1로 간선
		inde[edges[i][1]]++;
		outde[edges[i][0]]++;
		path[edges[i][0]].push_back(edges[i][1]);  
	}  
  
	for(int i = 1; i < 1000001; i++){  
		if(inde[i] == 0 && outde[i] >= 2){  
			answer.push_back(i);  
		}  
	}  
  
	vector<int> start = path[answer[0]];  
	for(int i = 0; i < start.size(); i++){  
		check(start[i]);  
	}  
    
	answer.push_back(shapeDonut);  
	answer.push_back(shapeOne);  
	answer.push_back(shapeInfinite);  
  
	return answer;  
}
