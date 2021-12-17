#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    int j = 0;
    while (i < A.size() && j < B.size()) {
        while (A[i] >= B[j] && j < B.size())
            j++;
        if (j >= B.size())
            break;
        if (A[i] < B[j])
            answer++;
        j++;
        i++;
    }
    return answer;
}
