#include <iostream>
#include <stack>

using namespace std;

int num_count;

int get_num_count(string str) {
	int count = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != ':' && str[i + 1] == ':')
			count++;
	}
	return count;
}

int main(void) {
	string str;
	cin >> str;

	num_count = get_num_count(str);
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);
	}

	string result = "";
	string chunk = "";
	while (!s.empty()) {
		char top = s.top();
		s.pop();
		if (top == ':') {
			int size = chunk.size();
			for (int i = 0; i < 4 - size; i++) {
				chunk = "0" + chunk;
			}
			result = ":" + chunk + result;
			chunk = "";
			if (s.top() == ':') {
				s.pop();
				for (int i = 0; i < 7 - num_count; i++) {
					result = ":0000" + result;
				}
			}
		} else {
			chunk = top + chunk;
		}
	}
	if (chunk.size()) {
		int size = chunk.size();
		for (int i = 0; i < 4 - size; i++) {
			chunk = "0" + chunk;
		}
	}
	result = chunk + result;
	if (result[0] == ':')
		result.erase(result.begin());
	cout << result << endl;
}
