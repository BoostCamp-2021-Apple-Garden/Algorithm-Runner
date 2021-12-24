#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
string chemical_str;

int main(void) {
	cin >> chemical_str;

	for (int i = 0; i < chemical_str.size(); i++) {
		int sum = 0;
		int tmp;
		switch (chemical_str[i]) {
			case 'H':
				s.push(1);
				break;
			case 'C':
				s.push(12);
				break;
			case 'O':
				s.push(16);
				break;
			case '(':
				s.push(-1);
				break;
			case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				tmp = s.top();
				s.pop();
				s.push(tmp * (chemical_str[i] - '0'));
				break;
			case ')':
				while (s.top() != -1) {
					int top = s.top();
					s.pop();
					sum += top;
				}
				s.pop();
				s.push(sum);
				break;
			default:
				break;
		}
	}

	int result = 0;
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << endl;
}
