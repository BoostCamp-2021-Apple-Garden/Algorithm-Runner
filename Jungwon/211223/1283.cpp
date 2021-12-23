#include <cstdio>
#include <set>
using namespace std;

int n;
set<char> s;

int main(void) {
    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++) {
        char str[60];
        fgets(str, sizeof(str), stdin);
        int idx = -1;
        for (int j=0; str[j]!='\n'; j++) {
            if (j!=0 && str[j-1]!=' ') continue;
            char c = str[j];
            if (c>='a') c = c - 'a' + 'A';
            if (s.find(c) == s.end()) {
                idx = j;
                s.insert(c);
                break;
            }
        }
        if (idx == -1) {
            for (int j=0; str[j]!='\n'; j++) {
                char c = str[j];
                if (c == ' ') continue;
                if (c>='a') c = c - 'a' + 'A';
                if (s.find(c) == s.end()) {
                    idx = j;
                    s.insert(c);
                    break;
                } 
            }
        }
        for (int j=0; str[j]!='\n'; j++) {
            if (j==idx) printf("[");
            printf("%c", str[j]);
            if (j==idx) printf("]");
        }
        printf("\n");
    }
}