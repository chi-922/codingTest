#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int seq = 1;
	bool flag = true;
	stack<int> st;
	queue<int> q;
	int N;
	int temp;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		q.push(temp);
	}

	while (seq <= N)
	{
		// �켱 q ���� Ȯ���ϱ�, q �� ���� ã�� ��ȣ �ƴ�. �׷� st�� Ȯ��
		if (!q.empty() && seq != q.front()) {
			if (!st.empty() && seq == st.top()) {
				seq++;
				st.pop();
			}
			else if (!st.empty() && seq != st.top()) {
				// st Ȯ�� �ߴµ� �� �ڵ� ã�� ��ȣ�� �ƴϾ�. �׷� q�� �ִ°� �̵�
				st.push(q.front());
				q.pop();
			}
			else {
				// st�� ����־������� q�� �ִ� �� �̵�
				st.push(q.front());
				q.pop();
			}
		}
		else if (!q.empty() && seq == q.front()) {
			seq++;
			q.pop();
		}
		// ���� q �� ����, st Ȯ���ϱ�
		else if (q.empty()) {
			if (!st.empty() && seq == st.top()) {
				seq++;
				st.pop();
			}
			else if (!st.empty() && seq != st.top()) {
				// st�� �ƴϾ�. �ٵ� �̹� q�� �����ϱ� ��
				flag = false;
				break;
			}
			else if (st.empty()) {
				break;
			}
		}
	}

	if (flag) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}
}