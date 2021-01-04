#include <cstring>
#include <cstdio>
#define maxn 85
char s[maxn];

int main(){

    scanf("%s", s);
    int kase = 1, n = strlen(s), ok = 1, m = 0;
    while (ok){
        for (int i = 0; i < n; i++) {
            if (s[i] != s[(i+kase)%n]){
                kase++;
                break;
            }
            m++; 
        }
        if (m == n)
        	ok = 0;
    }
    printf("%d\n", kase);
    return 0;
}
