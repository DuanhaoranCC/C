#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> PIL;

int main(){

    int n;
    while (cin >> n && n){
        map<pair<int,int>, int> m;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            PIL p1 = make_pair(a, b);
            PIL p2 = make_pair(b, a);
            if (m.count(p2)){
                k += 2;
                m[p2]--;
                if (!m[p2])
                    m.erase(p2);
            } else{
                if (!m.count(p1))
                    m[p1] = 0;
                m[p1]++;
            }
        }
        if (k == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
