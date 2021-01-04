#include <cstring>
#include <cstdio>
#define maxn 10005
int a[maxn];

int main(){

    int n, b[11];
    scanf("%d", &n);
    for (int i = 1; i <= 10000; i++) {
        a[i] = i;
    }
    while (n--){
        int N;
        scanf("%d", &N);
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= N; i++) {
            int x = a[i], y;
            while (x > 0){
                y = x%10;
                x /= 10;
                b[y]++;
            }
        }
        for (int j = 0; j < 9; j++) {
            printf("%d ", b[j]);
        }
        printf("%d\n", b[9]);
    }
    return 0;
}
