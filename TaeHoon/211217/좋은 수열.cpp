#include <iostream>
#include <string>
using namespace std;

int N;
string result;

bool is_good_numbers(string numbers) {
	int size = numbers.size();
	for (int i = 0; i < size / 2; i++) {
		int start = (size - 1 - i);
		int cmpStart = (size - 1 - 2 * i - 1);
		int strSize = i + 1;
		string str1 = numbers.substr(start, strSize);
		string str2 = numbers.substr(cmpStart, strSize);
		if (str1 == str2)
			return false;
	}
	return true;
}

void solution(string numbers, int count) {
	if (result != "")
		return ;
	if (count == 0) {
		if (result == "")
			result = numbers;
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		string newNumbers = numbers + to_string(i);
		if (is_good_numbers(newNumbers))
			solution(newNumbers, count - 1);
	}
}

int main() {
	cin >> N;

	solution("", N);
	cout << result;
}


	// 1 1
	// 2 12
	// 3 121
	// 4 1213
	// 5 12131
	// 6 121312
	// 7 1213121
	// 8 121321231
	// 9 1213212312
