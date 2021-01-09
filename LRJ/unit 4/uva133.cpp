#include <cstdio>
#include <cstring>
int a[25], b[25];

void init(int n){
    int k = 1;
    for (int i = 0; i < n; ++i) {
        a[i] = k++;
    }
}

int go(int i, int n, int k, int ok){
    int l = 0;
    while (1){
        if (b[i%n]){
            i = (i+ok+n)%n;
            l++;
        } else
            i = (i+ok+n)%n;
        if (l == k)
            break;
    }
    return i;
}

int main(){

    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    init(n);
    memset(b, 1, sizeof(b));
    int kase = 0, i = 0, j = n-1;
    for (;;) {
        if (kase == n)
            break;
        int x, y, l=0;
        /*while (1){
            if (b[i%n]){
                i = (i+1)%n;
                l++;
            } else
                i = (i+1)%n;
            if (l == k)
                break;
        }*/
        i = go(i, n, k, 1);
        x = a[(i-1+n)%n];
        l=0;
        /*while (1){
            if (b[j%n]){
                j = (j-1+n)%n;
                l++;
            } else
                j = (j-1+n)%n;
            if (l == m)
                break;
        }*/
        j = go(j, n, m, -1);
        y = a[(j+1)%n];
        if (x == y){
            printf("%d ", x);
            kase++;
            b[(i-1+n)%n] = 0;
        } else{
            printf("%d %d ", x, y);
            kase += 2;
            b[(i-1+n)%n] = 0;
            b[(j+1)%n] = 0;
        }
    }
    return 0;
}
