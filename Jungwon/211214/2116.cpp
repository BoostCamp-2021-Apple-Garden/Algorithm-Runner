#include <cstdio>

int dice[10000][6];
int index[10000][6];
int otherSide[6] = {5, 3, 4, 1, 2, 0};

int main(void) {
    int n, answer=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<6; j++) {
            scanf("%d", &dice[i][j]);
            index[i][dice[i][j]-1]=j;
        }
    }
    for (int i=0; i<6; i++) {
        int sum = 0;
        int bottom = dice[0][i];
        for (int j=0; j<n; j++) {
            int bottomIndex = index[j][bottom-1];
            int topIndex = otherSide[bottomIndex];
            int top = dice[j][topIndex];
            int maxValue = 6;
            if (top==maxValue || bottom==maxValue) maxValue--;
            if (top==maxValue || bottom==maxValue) maxValue--;
            sum += maxValue;
            bottom = top;
        }
        if (sum>answer) answer=sum;
    }
    printf("%d\n", answer);
    return 0;
}