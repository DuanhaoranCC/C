#include <cstdio>
#include <map>
using namespace std;
int x[1005], y[1005], sum;
typedef pair<int,int> PIL;
map<PIL, int> M;

int find(int k, int n, int& f){
    for (int i = f; i < n; ++i) {
        if (y[i] == k){
            sum += x[i];
            f = i;
            return i;
        }
    }
    return -1;
}

bool end(int m, float result){
    for (int i = 0; i < m; ++i) {
        float f = result - x[i];
        PIL p = make_pair(x[i]+f*2, y[i]);
        if (M.count(p))
            continue;
        else
            return false;
    }
    return true;
}

int main(){

    int n;
    scanf("%d", &n);
    while (n--){
        int m;
        sum = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            PIL p = make_pair(x[i], y[i]);
            M[p] = 1;
        }
        int kase=0, f=0;
        while (find(y[0], m, f) != -1){
            kase++;
            f++;
        }
        float result = (sum*1.0)/kase;
        if (end(m, result))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
