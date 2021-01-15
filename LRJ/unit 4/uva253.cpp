#include <cstdio>
#include <cstring>
char s[15];
int check(){
    for (int i = 0; i < 3; ++i) {
        char buf[8];
        sprintf(buf, "%c%c", s[i], s[6-i-1]);
        int ok = 0, kase;
        for (int j = 6; j < 9; ++j) {
            if (strchr(buf, s[j]) != NULL){
            	if (buf[0] == s[j]){
            		buf[0] = ' ';
            		kase = 0;
				}
            	else{
            		buf[1] = ' ';
            		kase = 1;
				}
            	if (strchr(buf, s[12-j+5]) != NULL){
            	    s[j] = s[12-j+5] =  ' ';
                    break;
            	}
            	else{
            		buf[kase] = s[j];
            		ok++;
				}
			}
            else
                ok++;
        }
        if (ok == 3)
            return 0;
    }
    return 1;
}

int main(){
    while (scanf("%s", s) == 1){
        if (check())
            printf("YES\n");
        else
            printf("FALSE\n");
    }
    return 0;
}
