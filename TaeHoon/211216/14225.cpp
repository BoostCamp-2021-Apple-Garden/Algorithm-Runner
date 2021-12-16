#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
int S[20];
int check[2000000] = {false, };

void dfs(int current, int index, int selected) {
	if (selected == 0) {
		check[current] = true;
		return;
	}
	for (; index < n; index++) {
		dfs(current + S[index], index + 1, selected - 1);
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}

	for (int selected = n; selected > 0; selected--) {
		dfs(0, 0, selected);
	}

	int result = 1;
	while (1) {
		if (check[result] == false) {
			cout << result << endl;
			break;
		}
		result++;
	}
}
