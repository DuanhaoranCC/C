#include <cstdio>
#include <cstring>
#include <cctype>
char graph[10][10];
int a[10][10];

int main(){

    int r, c;
    while (scanf("%d", &r) && r){
        scanf("%d", &c);
        int kase = 1;
        memset(a, 0, sizeof(a));
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                graph[i][j] = getchar();
                if (isalpha(graph[i][j]) && (graph[i][j-1]=='*' || j-1<0 || i-1<0
                                               || graph[i-1][j]=='*'))
                    a[i][j] = kase++;
            }
            getchar();
        }
        kase = 1;
        printf("puzzle #%d:\n", kase);
        printf("Across\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] != 0){
                    printf("  %d.", a[i][j]);
                    int k;
                    for (k = j; k < c; k++) {
                        if (isalpha(graph[i][k]))
                            printf("%c", graph[i][k]);
                        else
                            break;
                    }
                    j = k;
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (a[i][j] != 0){
                    printf("  %d.", a[i][j]);
                    for (i; i < r; i++) {
                        if (isalpha(graph[i][j]))
                            printf("%c", graph[i][j]);
                        else
                            break;
                    }
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
