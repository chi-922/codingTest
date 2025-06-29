#include <iostream>
#include <queue>

using namespace std;

int T, m, temp;

int main() {

	cin >> T;

	while (T--)
	{
		cin >> m >> temp;  // ù��° ���ڸ� �޾ƿ���

		priority_queue<int, vector<int>, less<>> max_heap;
		priority_queue<int, vector<int>, greater<>> min_heap;

		cout << (m + 1) / 2 << "\n";  // �׽�Ʈ �� ó�� ������ ��� ���� ���
		cout << temp << " ";  // ó�� Ȧ����° �߾Ӱ��� ������ ù��° �Է� ����

        // �� ���� 2���� �޾Ƽ� ��� ��
        for (int i = 0; i < m / 2; i++) {
            int a, b;
            cin >> a >> b;

            if (a > b) swap(a, b);

            if (a <= temp && temp <= b) {
                max_heap.push(a);
                min_heap.push(b);
            }
            else if (b <= temp) {
                max_heap.push(a); max_heap.push(b);
                min_heap.push(temp);
                temp = max_heap.top(); max_heap.pop();
            }
            else {
                min_heap.push(a); min_heap.push(b);
                max_heap.push(temp);
                temp = min_heap.top(); min_heap.pop();
            }
            cout << temp << " ";
        }
        cout << "\n";
	}
}