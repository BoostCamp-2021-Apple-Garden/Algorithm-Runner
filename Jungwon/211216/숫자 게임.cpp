#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i=0, j=0;
    while (i<size && j<size) {
        if (A[i] < B[j]) {
            i++;
            answer++;
        }
        j++;
    }
    return answer;
}