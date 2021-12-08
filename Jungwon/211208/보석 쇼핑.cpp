#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool shouldUpdate(vector<int> v, int left, int right) {
    if (right-left<v[1]-v[0]) return true;
    if (right-left==v[1]-v[0]&&left<v[0]) return true;
    else return false;
}

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    vector<int> v(2);

    int left=0, right=0;
    for (int i=0; i<gems.size(); i++) {
        string gem = gems[i];
        if (m.find(gem) == m.end()) {
            m[gem]=1;
            right=i;
            v[1]=i;
            v[0]=left;
        }
        else {
            m[gem]++;
            if (gem==gems[left]) {
                right=i;
                while(m[gems[left]]>1) {
                    m[gems[left]]--;
                    left++;
                }
            }
            if (shouldUpdate(v, left, right)) {
                v[0]=left;
                v[1]=right;
            }
        }
    }

    v[0]++;
    v[1]++;

    return v;
}