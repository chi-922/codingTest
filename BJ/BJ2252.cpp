#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<int> num_entry(v + 1, 0);
    vector<vector<int>> adj_list(v + 1);

    // ���� �Է�
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        num_entry[b]++;
    }

    queue<int> q;
    vector<int> result;

    // �������� 0�� ��� ť�� �߰�
    for (int i = 1; i <= v; i++) {
        if (num_entry[i] == 0) {
            q.push(i);
        }
    }

    // ��������
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int next : adj_list[now]) {
            if (--num_entry[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
