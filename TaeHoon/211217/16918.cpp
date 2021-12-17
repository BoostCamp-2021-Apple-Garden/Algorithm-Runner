#include <iostream>

using namespace std;

int R, C, N;
char arr[200][200];
int remain_times[200][200] = {0, };

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

void make_bomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '.') {
				arr[i][j] = 'O';
				remain_times[i][j] = 3;
			}
		}
	}
}

void destroy(int y, int x) {
	remain_times[y][x] = 0;
	arr[y][x] = '.';
	for (int i = 0; i < 4; i++) {
		int deltaY = y + dy[i];
		int deltaX = x + dx[i];
		if (is_in_range(deltaY, deltaX) && remain_times[deltaY][deltaX] != 1) {
			arr[deltaY][deltaX] = '.';
			remain_times[deltaY][deltaX] = 0;
		}
	}
}

void decrease_remain_time() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (remain_times[i][j] > 1)
				remain_times[i][j]--;
		}
	}
}

int main(void) {
	// 입력
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				remain_times[i][j] = 3;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		decrease_remain_time();
		if (i % 2 == 1)
			make_bomb();
		else {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (remain_times[j][k] == 1) {
						destroy(j, k);
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}
