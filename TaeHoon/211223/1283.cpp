#include <iostream>

using namespace std;

int N;
bool visited[27] = {false, };

char to_lower(char c) {
	if (c >= 'a' && c <= 'z')
		return c;
	else if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	return c;
}

bool is_alpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string hot_keyed(string option) {
	string result = "";
	bool is_setting = false;

	for (int i = 0; i < option.size(); i++) {
		if (i == 0 || (i > 0 && option[i - 1] == ' ')) {
			char lower_case = to_lower(option[i]);
			int lower_index = lower_case - 'a';
			if (is_alpha(option[i]) && !visited[lower_index] && !is_setting) {
				visited[lower_index] = true;
				is_setting = true;
				result = result + "[" + option[i] + "]";
			} else {
				result += option[i];
			}
		} else {
			result += option[i];
		}
	}

	if (is_setting)
		return result;
	result = "";

	for (int i = 0; i < option.size(); i++) {
		char lower_case = to_lower(option[i]);
		int lower_index = lower_case - 'a';
		if (is_alpha(option[i]) && !visited[lower_index] && !is_setting) {
			visited[lower_index] = true;
			is_setting = true;
			result = result + "[" + option[i] + "]";
		} else {
			result += option[i];
		}
	}
	return result;
}

int main(void) {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string option;
		// cin >> option;
		getline(cin, option);
		cout << hot_keyed(option) << endl;
	}
}
