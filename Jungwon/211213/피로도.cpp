#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer=0;
    vector<int> v;
    for (int i=0; i<dungeons.size(); i++) v.push_back(i);
    do {
        int pirodo=k, cnt=0;
        for (int i=0; i<dungeons.size(); i++) {
            int index=v[i];
            if (pirodo < dungeons[index][0] || pirodo < dungeons[index][1]) break;
            pirodo -= dungeons[index][1];
            cnt++;
        }
        if (cnt>answer) answer=cnt;
    } while(next_permutation(v.begin(), v.end()));
    return answer;
}