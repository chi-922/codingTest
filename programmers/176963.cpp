// 추억 점수

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
  	map <string, int> m;
  
  	for (int i = 0; i < name.size(); i++) {
  		m[name[i]] = yearning[i];
  	}
  
  	for (int i = 0; i < photo.size(); i++) {
  		int cnt = 0;
      
  		for (int j = 0; j < photo[i].size(); j++) {
  			cnt += m[photo[i][j]];
  		}
      
  		answer.push_back(cnt);
  	}
      
    return answer;
}
