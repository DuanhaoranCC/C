#include <cstring>
#include <cstdio>
#include <cctype>
#define maxn 85

int main(){

    char s[maxn];
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        int n = strlen(s), t, sum = 0, i = 0;
        while (i < n){
            t = 0;
            while (s[i] == 'O'){
                ++t;
                sum += t;
                i++;
            }
            i++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
