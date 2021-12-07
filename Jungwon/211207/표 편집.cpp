#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct Node* nptr;
typedef struct Node {
    nptr left;
    int num;
    nptr right;
} NODE;

nptr head = NULL;
nptr current = NULL;
nptr top = NULL;

void up(int x) {
    for (int i=0; i<x; i++) {
        current = current -> left;
    }
}

void down(int x) {
    for (int i=0; i<x; i++) {
        current = current -> right;
    }
}

void push(nptr target) {
    if (top == NULL) top = target;
    else {
        target -> right = top;
        top = target;
    }
}

nptr pop() {
    nptr target = top;
    top = top -> right;
    target -> right = NULL;
    return target;
}

void remove() {
    if (current -> left != NULL) current -> left -> right = current -> right;
    else head = current -> right;
    if (current -> right != NULL) current -> right -> left = current -> left;
    
    nptr target = current;
    if (current -> right != NULL) current = current -> right;
    else current = current -> left;
    
    target -> right = NULL;
    push(target);
}

void rollback() {
    nptr target = pop();
    if (target -> left == NULL) {
        target -> right = head;
        head -> left = target;
        head = target;
    } else {
        nptr left = target -> left;
        nptr right = target -> left -> right;
        if (right != NULL) {
            target -> right = right;
            right -> left = target;
        }
        left -> right = target;
    }
}

void initialize(int n, int k) {
    nptr last;
    for (int i=0; i<n; i++) {
        nptr temp = (nptr)malloc(sizeof(NODE));
        temp -> num = i;
        temp -> right = NULL;
        if (i==0) {
            temp -> left = NULL;
            head = temp;
            last = temp;
        } else {
            last -> right = temp;
            temp -> left = last;
            last = temp;
        }
    }
    
    current = head;
    down(k);
}

int getNumber(string s) {
    s.erase(0, 2);
    int result = 0;
    for (int i=0; i<s.size(); i++) {
        result = result * 10 + (s[i] -'0');
    }
    return result;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    initialize(n, k);
    for (int i=0; i<cmd.size(); i++) {
        char op = cmd[i][0];
        if (op == 'U') {
            int x = getNumber(cmd[i]);
            up(x);
        } else if (op == 'D') {
            int x = getNumber(cmd[i]);
            down(x);
        } else if (op == 'C') {
            remove();
        } else {
            rollback();
        }
    }
    
    nptr p = head;
    for (int i=0; i<n; i++) {
        if (p != NULL && i == (p -> num)) {
            answer += "O";
            p = p -> right;
        } else {
            answer += "X";
        }
    }
    return answer;
}