#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <deque>
using namespace std;
vector<int> v;
map<int,int> m;
queue<int> q;
deque<int> d[1005];

void init(){
    v.clear();
    m.clear();
    q = queue<int>();
}

void en(int n){
    if (!v[m[n]])
        q.push(m[n]);
    v[m[n]]++;
    d[m[n]].push_back(n);
}

void de(){
    int top = q.front();
    cout << d[top].front() << endl;
    if (v[top] == 1)
        q.pop();
    d[top].pop_front();
    v[top]--;
}

int main(){

    int t, n;
    while (cin >> t && t){
        for (int i = 0; i < t; ++i) {
            cin >> n;
            while (n--){
                int a;
                cin >> a;
                m[a] = i;
            }
            v.push_back(0);
        }
        while(1){
            string s;
            cin >> s;
            if (s[0] == 'E'){
                cin >> n;
                en(n);
            }
            if (s[0] == 'D')
                de();
            if (s[0] == 'S')
                break;
        }
        for (int j = 0; j < t; ++j) {
            d[j] = deque<int>();
        }
        init();
    }
    return 0;
}
