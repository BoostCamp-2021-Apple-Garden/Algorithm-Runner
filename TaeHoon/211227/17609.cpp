#include <iostream>
#define BOTH 3
#define LEFT_CONSUME 2
#define RIGHT_CONSUME 1
#define NONE 0

using namespace std;

int N;

int solution(string str) {
	int left = 0;
	int right = str.size() - 1;
	int snap_left = -1;
	int snap_right = -1;
	int coin = BOTH;
	bool is_similar = false;

	while (left <= right) {
		if (str[left] != str[right]) {
			// cout << str[left] << ", " << str[right] << endl;
			if (is_similar && coin == NONE)
				return 2;
			if ((str[left + 1] == str[right] && coin == BOTH) ||
			(str[snap_left + 1] == str[snap_right] && coin == RIGHT_CONSUME)) {
				if (coin == RIGHT_CONSUME) {
					coin = NONE;
					left = snap_left;
					right = snap_right;
				}
				else {
					coin = LEFT_CONSUME;
					snap_left = left;
					snap_right = right;
				}
				left++;
			}
			else if ((str[left] == str[right - 1] && coin == BOTH) ||
			(str[snap_left] == str[snap_right - 1] && coin == LEFT_CONSUME)) {
				if (coin == LEFT_CONSUME) {
					coin = NONE;
					left = snap_left;
					right = snap_right;
				}
				else {
					coin = RIGHT_CONSUME;
					snap_left = left;
					snap_right = right;
				}
				right--;
			}
			else
				return 2;
			is_similar = true;
		}
		left++;
		right--;
	}
	return is_similar;
}

int main(void) {
	cin >> N;

	for (int i = 0 ; i < N; i++) {
		string str;
		cin >> str;
		cout << solution(str) << endl;
	}
}
