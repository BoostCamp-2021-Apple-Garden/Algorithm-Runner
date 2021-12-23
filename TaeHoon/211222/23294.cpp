#include <iostream>
#include <vector>

using namespace std;

struct Page {
	int index;
	int capacity;
	Page(int index, int capacity) : index(index), capacity(capacity) {}
	bool operator == (const Page &rhs) {
		return this->index == rhs.index;
	}
};

vector<Page> v_backward;
int back_start = 0;
int back_end = 0;

vector<Page> v_forward;
int forward_start = 0;
int forward_end = 0;

Page current = Page(0, 0);
bool is_first_visit = true;

vector<Page> available_pages;

int N, Q, C;

int get_all_capacity() {
	int sum = 0;
	if (is_first_visit)
		return 0;
	for (int i = back_start; i < back_end; i++) {
		sum += v_backward[i].capacity;
	}
	int front_sum = 0;
	for (int i = forward_start; i < forward_end; i++) {
		sum += v_forward[i].capacity;
		front_sum += v_forward[i].capacity;
	}
	return sum + current.capacity;
}

void to_v_backward() {
	if (back_start >= back_end) {
		return ;
	}
	v_forward.push_back(current);
	current = v_backward[back_end - 1];
	v_backward.erase(v_backward.end() - 1);
	forward_end++;
	back_end--;
}

void to_v_forward() {
	if (forward_start >= forward_end) {
		return ;
	}
	v_backward.push_back(current);
	current = v_forward[forward_end - 1];
	v_forward.erase(v_forward.end() - 1);
	back_end++;
	forward_end--;
}

void access(Page page) {
	forward_start = forward_end;
	if (!is_first_visit) {
		// Page newPage = Page(current.index, current.capacity);
		v_backward.push_back(current);
		back_end++;
		current = page;
	}
	else {
		is_first_visit = false;
		current = page;
	}
	while (get_all_capacity() > C) {
		back_start++;
	}
}

void compress() {
	for (int i = back_start; i < back_end; i++) {
		while (i + 1 < back_end && v_backward[i] == v_backward[i + 1]) {
			v_backward.erase(v_backward.begin() + i + 1);
			back_end--;
		}
	}
}

void display_all() {
	cout << "back cache\n";
	for (int i = back_start; i < back_end; i++)
		cout << v_backward[i].index << " ";
	cout << "\n";

	cout << "front cache\n";
	for (int i = forward_start; i < forward_end; i++)
		cout << v_forward[i].index << " ";
	cout << "\n";

	cout << "current : " << current.index << endl << endl;
}

int main(void) {
	cin >> N >> Q >> C;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		available_pages.push_back(Page(i + 1, temp));
	}
	for (int i = 0; i < Q; i++) {
		char command;
		cin >> command;
		int page_index;

		switch (command) {
			case 'A':
				cin >> page_index;
				access(available_pages[page_index - 1]);
				break;
			case 'B':
				to_v_backward();
				break;
			case 'F':
				to_v_forward();
				break;
			case 'C':
				compress();
				break;
			default: break;
		}
		// display_all();
	}

	if (!is_first_visit)
		cout << current.index << "\n";
	if (back_start >= back_end) {
		cout << "-1\n";
	}
	else {
		for (int i = back_end - 1; i >= back_start; i--)
			cout << v_backward[i].index << " ";
		cout << "\n";
	}

	if (forward_start >= forward_end) {
		cout << "-1\n";
	}
	else {
		for (int i = forward_end - 1; i >= forward_start; i--)
			cout << v_forward[i].index << " ";
		cout << "\n";
	}
}
