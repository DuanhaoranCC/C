#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
vector<string> v;

bool find(string s, int n){
    string buf = s.substr(0, n);
    string buff = s.substr(n, s.length());
    return m.count(buf) && m.count(buff);
}
int main(){

    string s;
    while (cin >> s){
        m[s] = 1;
    }
    for (auto & it : m) {
        for (int i = 1; i < it.first.length(); ++i) {
            if (find(it.first, i))
                v.push_back(it.first);
        }
    }
    for (const auto & i : v) {
        cout << i << endl;
    }
    return 0;
}
