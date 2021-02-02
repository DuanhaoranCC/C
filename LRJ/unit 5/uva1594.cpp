#include <iostream>
#include <cstring>
#include<cmath>
using namespace std;

int main(){

    int n;
    cin >> n;
    while (n--){
        int m, a[20], kase=0, f = 0;
        cin >> m;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        while (kase != m){
            kase = 0;
            int k = a[0];
            for (int i = 0; i < m; ++i) {
                if (i != (m-1))
                    a[i] = abs(a[i] - a[(i+1)%m]);
                else
                    a[i] = abs(a[i] - k);
                if (!a[i])
                    kase++;
            }
            f++;
            if (f == 1000)
                break;
        }
        if (kase == m)
            cout << "ZERO" << endl;
        else
            cout << "LOOP" << endl;
    }
    return 0;
}
