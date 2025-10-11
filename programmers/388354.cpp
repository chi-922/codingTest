#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    // 노드 번호를 0..K-1로 압축
    int K = nodes.size();
    unordered_map<int,int> id2idx;
    id2idx.reserve(K * 2);  // 사이즈, 메모리 확보 / 해시테이블 자료구조인데 리해싱 막기위해 넉넉히
    for (int i = 0; i < K; ++i) id2idx[nodes[i]] = i;

    // 인접리스트 & degree
    vector<vector<int>> adj(K);
    vector<int> deg(K, 0);
    adj.reserve(K);

    for (const auto& e : edges) {
        auto itu = id2idx.find(e[0]);
        auto itv = id2idx.find(e[1]);
        if (itu == id2idx.end() || itv == id2idx.end()) continue; // 혹시 모를 이상치 방어
        int u = itu->second, v = itv->second;  // 압축된 노드 번호 즉, value 값 가져옴.
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    vector<char> vis(K, 0);
    int eot = 0, reot = 0;

    // 컴포넌트별로 한 번만 순회
    for (int s = 0; s < K; ++s) if (!vis[s]) {
        queue<int> q;
        q.push(s); vis[s] = 1;

        int eq_cnt = 0;   // p==d 인 노드 개수
        int neq_cnt = 0;  // p!=d 인 노드 개수

        while (!q.empty()) {
            int x = q.front(); q.pop();

            int p = (nodes[x] & 1);   // 번호의 홀짝
            int d = (deg[x] & 1);     // degree의 홀짝

            if (p == d) eq_cnt++;
            else        neq_cnt++;

            for (int y : adj[x]) if (!vis[y]) {
                vis[y] = 1;
                q.push(y);
            }
        }

        // 컴포넌트가 홀짝 트리가 될 수 있는가? => eq_cnt == 1
        if (eq_cnt == 1) eot++;
        // 컴포넌트가 역홀짝 트리가 될 수 있는가? => neq_cnt == 1
        if (neq_cnt == 1) reot++;
    }

    return {eot, reot};
}
