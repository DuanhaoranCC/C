#include <cstdio>
#include <cstring>
#include <cctype>
char graph[5][5];
int x, y;

int init(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int c = getchar();
            if (c == 'Z')
                return 0;
            if (c == ' '){
                x = i;
                y = j;
            }
            if (c != EOF)
                graph[i][j] = c;
        }
        getchar();
    }
    return 1;
}

void print_graph(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++)
            printf("%c ", graph[i][j]);
        printf("%c\n", graph[i][4]);
    }
}

int main(){

    int kase = 1;
    for(;;){
        if (!init())
            break;
        int c, flag = 1;
        while ((c = getchar()) != EOF && c != '0'){
            if (c == 'A'){
                graph[x][y] = graph[x-1][y];
                if (x - 1 < 0)
                    flag = 0;
                graph[--x][y] = ' ';
            } else if (c == 'B'){
                graph[x][y] = graph[x+1][y];
                if (x + 1 > 4)
                    flag = 0;
                graph[++x][y] = ' ';
            } else if (c == 'L'){
                graph[x][y] = graph[x][y-1];
                if (y - 1 < 0)
                    flag = 0;
                graph[x][--y] = ' ';
            } else if (c == 'R'){
                graph[x][y] = graph[x][y+1];
                if (y + 1 > 4)
                    flag = 0;
                graph[x][++y] = ' ';
            }
        }
        printf("Puzzle #%d:\n", kase++);
        if (flag)
            print_graph();
        else
            printf("This puzzle has no final configuration.\n");
    }

    return 0;
}
