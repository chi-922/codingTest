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
		// 우선 q 부터 확인하기, q 젤 앞이 찾는 번호 아님. 그럼 st도 확인
		if (!q.empty() && seq != q.front()) {
			if (!st.empty() && seq == st.top()) {
				seq++;
				st.pop();
			}
			else if (!st.empty() && seq != st.top()) {
				// st 확인 했는데 젤 뒤도 찾는 번호가 아니야. 그럼 q에 있는거 이동
				st.push(q.front());
				q.pop();
			}
			else {
				// st가 비어있어있으면 q에 있는 거 이동
				st.push(q.front());
				q.pop();
			}
		}
		else if (!q.empty() && seq == q.front()) {
			seq++;
			q.pop();
		}
		// 만약 q 줄 없음, st 확인하기
		else if (q.empty()) {
			if (!st.empty() && seq == st.top()) {
				seq++;
				st.pop();
			}
			else if (!st.empty() && seq != st.top()) {
				// st도 아니야. 근데 이미 q는 없으니까 끝
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