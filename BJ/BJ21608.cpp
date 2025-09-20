#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> classroom;
map<int, vector<int>> bf;
int score[5] = { 0, 1, 10, 100, 1000 };
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void arrange(int st, vector<int>* pbf) {
	// vector<vector<int>> satisfy(n, vector<int>(n, 0));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	
	int maxv = 0;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (classroom[r][c]) continue;
			int bfCnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int nr = r + dr[d], nc = c + dc[d];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				// 친구가 있고 그게 내 베프라면
				if (classroom[nr][nc] && (find(pbf->begin(), pbf->end(), classroom[nr][nc]) != pbf->end())) bfCnt++;
			}
			
			if (maxv == score[bfCnt])
			{
				pq.push({ r, c });
			}
			else if (maxv < score[bfCnt]) {
				while (!pq.empty()) pq.pop();
				maxv = score[bfCnt];
				pq.push({ r, c });
			}
		}
	}

	if (pq.size() > 1) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Realpq;
		int maxVaccum = 0;
		while(!pq.empty())
		{
			int r = pq.top().first, c = pq.top().second;
			pq.pop();
			int cnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int nr = r + dr[d], nc = c + dc[d];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				// 빈자리 캐치
				if (!classroom[nr][nc]) cnt++;
			}

			if (maxVaccum == cnt)
			{
				Realpq.push({ r, c });
			}
			else if (maxVaccum < cnt) {
				while (!Realpq.empty()) Realpq.pop();
				maxVaccum = cnt;
				Realpq.push({ r, c });
			}
		}

		// Realpq 제일 앞에꺼가 st의 자리
		classroom[Realpq.top().first][Realpq.top().second] = st;
		return;
	}
	else {
		// pq 오직 하나가 st의 자리
		classroom[pq.top().first][pq.top().second] = st;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int arr[400] = { 0, };
	classroom.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n * n; i++)
	{
		int st, bf1, bf2, bf3, bf4;
		cin >> st >> bf1 >> bf2 >> bf3 >> bf4;

		arr[i] = st;
		bf[st] = { bf1, bf2, bf3, bf4 };
	}

	// classroom[n / 2][n / 2] = arr[0];

	for (int i = 0; i < n * n; i++)
	{
		vector<int>* pbf;
		pbf = &bf[arr[i]];
		arrange(arr[i], pbf);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int st = classroom[i][j];
			int cnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int nr = i + dr[d], nc = j + dc[d];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				// 친구가 내 베프라면
				if (find(bf[st].begin(), bf[st].end(), classroom[nr][nc]) != bf[st].end()) cnt++;
			}
			ans += score[cnt];
		}
	}

	cout << ans;
	return 0;
}