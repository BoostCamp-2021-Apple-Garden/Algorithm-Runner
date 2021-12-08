#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> leftFirst(vector<string> gems, map<string, int> tempMap) {
    vector<int> v;
    int left=0, right=gems.size()-1;
    
    while(true) {
        if (tempMap[gems[left]]>1) {
            tempMap[gems[left]]--;
            left++;
        }
        if (tempMap[gems[right]]>1) {
            tempMap[gems[right]]--;
            right--;
        }
        if (tempMap[gems[left]]==1&&tempMap[gems[right]]==1) break;
    }
    v.push_back(left+1);
    v.push_back(right+1);
    return v;
}

vector<int> rightFirst(vector<string> gems, map<string, int> tempMap) {
    vector<int> v;
    int left=0, right=gems.size()-1;
    
    while(true) {
        if (tempMap[gems[right]]>1) {
            tempMap[gems[right]]--;
            right--;
        }
        if (tempMap[gems[left]]>1) {
            tempMap[gems[left]]--;
            left++;
        }
        if (tempMap[gems[left]]==1&&tempMap[gems[right]]==1) break;
    }
    v.push_back(left+1);
    v.push_back(right+1);
    return v;
}

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    vector<int> v1, v2;
    
    for (int i=0; i<gems.size(); i++) {
        string gem = gems[i];
        if (m.find(gem) == m.end()) m[gem]=1;
        else m[gem]++;
    }
    
    v1 = leftFirst(gems, m);
    v2 = rightFirst(gems, m);
    
    return v1[1]-v1[0] < v2[1]-v2[0] ? v1 : v2;
}