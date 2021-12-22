#include <iostream>
#define STA 0
#define LDA 1
#define BEQ 2
#define NOP 3
#define DEC 4
#define INC 5
#define JMP 6
#define HLT 7

using namespace std;

int mem[32];

string int_to_string(int num) {
	string result = "";
	while (num) {
		result = char((num % 2) + '0') + result;
		num /= 2;
	}
	while (result.size() < 8) {
		result = "0" + result;
	}
	return result;
}

int string_to_int(string mem) {
	int result = 0;
	for (int i = 0; i < mem.size(); i++) {
		result *= 2;
		result += mem[i] - '0';
	}
	return result;
}

pair<int, int> command_parser(int command) {
	string command_str = int_to_string(command);
	int command_type = string_to_int(command_str.substr(0, 3));
	int memory = string_to_int(command_str.substr(3, 5));
	return make_pair(command_type, memory);
}

void calculate(int &pc, int &adder, int command_type, int target_memory) {
	switch (command_type) {
		case STA:
			mem[target_memory] = adder;
			break;
		case LDA:
			adder = mem[target_memory];
			break;
		case BEQ:
			if (adder == 0)
				pc = target_memory;
			break;
		case NOP:
			break;
		case DEC:
			if (adder == 0)
				adder = 256;
			adder -= 1;
			break;
		case INC:
			adder += 1;
			adder %= 256;
			break;
		case JMP:
			pc = target_memory;
			break;
		default:
			break;
	}
}

string solution() {
	int pc = 0;
	int adder = 0;
	while (1) {

		pair<int, int> parsed = command_parser(mem[pc]);
		int command_type = parsed.first;
		int target_memory = parsed.second;

		if (command_type == HLT)
			break;
		pc++;
		if (pc == 32)
			pc = 0;
		calculate(pc, adder, command_type, target_memory);
	}
	return int_to_string(adder);
}

int main(void) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		string tmp;
		cin >> tmp;
		if (cin.eof()) {
			// cout << "EOF" << endl;
			break;
		}
		mem[0] = string_to_int(tmp);
		for (int i = 1; i < 32; i++) {
			cin >> tmp;
			mem[i] = string_to_int(tmp);
		}
		cout << solution() << "\n";
	}
}
