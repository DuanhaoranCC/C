#include <cstdio>
#include <cstring>
char s[105], t[105];

int main(){

    while (scanf("%s%s", s, t)){
        int kase = 0;
        for (int i = 0; i < strlen(t); i++) {
            if (t[i] == s[kase])
                kase++;
        }
        if (kase == strlen(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
