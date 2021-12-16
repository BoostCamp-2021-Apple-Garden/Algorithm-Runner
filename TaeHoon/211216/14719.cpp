#include<iostream>

using namespace std;

int arr[500]; int y, x;

int find_next_wall(int start) {
	for (int i = start; i < x; i++) {
		if (arr[i] != 0)
			return i;
	}
	return -1;
}

int measure_horizon_water(int index, int height) {
	int result = 0;

	for (int i = 1; i <= height; i++) {
		int j;
		int count = 0;
		for (j = index + 1; j < x; j++) {
			if (i <= arr[j]) {
				result += count;
				break;
			}
			count++;
		}
	}
	return result;
}

int main(void) {

	// 입력
	cin >> y >> x;
	for (int i = 0; i < x; i++)
		cin >> arr[i];


	int result = 0;
	int start = find_next_wall(0);
	for (int i = start; i < x; i++) {
		result += measure_horizon_water(i, arr[i]);
	}
	cout << result << endl;
}
