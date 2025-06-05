#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    stack<char> st;

    while (getline(cin, line)) {
        if (line == ".") break;

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '(' || line[i] == '[') {
                st.push(line[i]);
            }
            else if (line[i] == ')') {
                // 무조건 st에 ( 가 제일 위에 있어야 정상
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(line[i]);
                    break;
                }
            }
            else if (line[i] == ']') {
                // 무조건 st에 [ 가 제일 위에 있어야 정상
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(line[i]);
                    break;
                }
            }
        }

        if (st.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
            while (!st.empty()) st.pop();
        }
    }
}