#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt = 0, answer = 0;
string S;
bool startFlag = false;
vector<int> v;

int main(void) {
    cin >> N >> M;
    cin >> S;
    for (int i = 0; i < M; i++) {
        if (S[i] == 'I') {
            if (startFlag) {
                if (cnt !=0) v.push_back(cnt);
                cnt = 0;
            }
            else startFlag = true;
        } else {
            if (startFlag) {
                if (S[i+1] == 'I') {
                    cnt++;
                    i++;
                } else {
                    startFlag = false;
                    if (cnt !=0) v.push_back(cnt);
                    cnt = 0;
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < N) continue;
        answer += (v[i] + 1 - N);
    }
    cout << answer << endl;
    return 0;
}