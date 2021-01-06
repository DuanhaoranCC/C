#include <cstdio>
#include <cstring>
char graph[55][1005];
const char* s = "ACGT";
char sf[1005];
int a[100];

int main(){

    int n;
    scanf("%d", &n);
    while (n--){
        int r, c, sum = 0;
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", graph[i]);
        }
        for (int j = 0; j < c; j++) {
            memset(a, 0, sizeof(a));
            for (int i = 0; i < r; i++) {
                a[graph[i][j]]++;
            }
            int max = -1, kase = 0;
            for (int k = 0; k < 4; k++) {
                if (max < a[s[k]]){
                	max = a[s[k]];
                	kase = k;
								}    
            }
            sum += r-max;
            sf[j] = s[kase];
        }
        printf("%s\n", sf);
        printf("%d\n", sum);
    }
    return 0;
}
