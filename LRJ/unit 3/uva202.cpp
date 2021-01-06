#include <cstdio>
#include <cstring>
int r[3005], u[3005], s[3005];

int main()
{
    int n, m, t;
    while (scanf("%d%d", &n, &m)!=EOF)
    {
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        int count = 0;
        int t = n;
        r[count++] = n/m;
        n = n%m;
        while (!u[n] && n)
        {
            u[n] = count;//存除数对应的循环小数位置，为了找到循环节长度
            s[count] = n;//存循环小数位置对应的除数，为了找到循环节的开始位置输出"("
            r[count++] = 10 * n / m;//得到余数
            n = 10 * n%m;//得到新除数
        }
        printf("%d/%d = %d",t,m,r[0]);
        printf(".");
        for (int i = 1; i < count&&i<=50; i++)
        {
            if (s[i] == n)printf("(");
            printf("%d",r[i]);
        }
        if (count>50)printf("...");
        if (!n)printf("(0");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n",!n?1:count-u[n]);
    }


    return 0;
}
