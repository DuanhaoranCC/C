#include <cstring>
#include <cstdio>
#include <cctype>
#define maxn 50
const char* rev = "CHON";
const float mol[] = {12.01, 1.008, 16.00, 14.01};
char s[maxn];

int main(){

    int N;
    scanf("%d", &N);
    while (N--){
        scanf("%s", s);
        int n = strlen(s), i = 0;
        float sum = 0.0;
        while (i < n){
            int M = 0, j = 0;
            for (j; s[i] != rev[j]; j++);
            i++;
            while (isdigit(s[i]) && i < n){
                if (M == 0)
                    M = s[i] - '0';
                else
                    M = M * 10 + (s[i] - '0');
                i++;
            }
            if (M == 0)
                M = 1;
            sum = sum + M*mol[j];
        }
        printf("%.3f", sum);
        printf("g/mol\n");
    }

    return 0;
}
