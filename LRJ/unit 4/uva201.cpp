#include <cstdio>
#include <cstring>
int graph[10][10], graph2[10][10], list[10];
int readchar(){
    int c;
    for (;;) {
        c = getchar();
        if (c != '\n' && c != '\r')
            return c;
    }
}

int judge(int len, int x, int y){
    for (int i = 0; i < len; ++i) {
        if (!graph[x][y+i] || !graph2[x+i][y])
            return 0;
        if (!graph[x+len][y+i] || !graph2[x+i][y+len])
            return 0;
    }
    return 1;
}

int main(){

    int n, m, kase = 1, ok = 0, flag;
    while (scanf("%d%d", &n, &m) == 2){
        memset(graph, 0, sizeof(graph));
        memset(graph2, 0, sizeof(graph2));
        memset(list, 0, sizeof(list));
        ok = !ok;
        flag = 0;
        for (int i = 0; i < m; ++i) {
            int c = readchar();
            int x, y;
            scanf("%d%d", &x, &y);
            if (c == 'H'){
                graph[x][y] = 1;
            } else if (c == 'V'){
                graph2[y][x] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n-i; ++j) {
                for (int k = 1; k <= n-i; ++k) {
                    if (judge(i, j, k))
                        list[i]++;
                }
            }
        }
        printf("Problem #%d\n\n", kase++);
        for(int i=1;i<=n;i++){
            if (list[i])
                printf("%d square (s) of size %d\n", list[i], i);
            else
                flag++;
        }
        if (ok)
            printf("\n**********************************\n\n");
        if (flag == n)
            printf("No completed squares can be found.\n");
    }
    return 0;
}
