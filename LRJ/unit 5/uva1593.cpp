#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> v[1005];

void print(string s, int len){
    cout << s;
    for (int i = 0; i < len; ++i) {
        cout << " ";
    }
}
int a[190];

int main(){

    string s;
    int i = 0, k = 0;
    while (getline(cin, s)){
        stringstream ss(s);
        string buf;
        while (ss >> buf){
            v[i].push_back(buf);
            if (!i)
                a[k++] = buf.length();
        }
        i++;
    }
    for (int j = 0; j < i; ++j) {
        for (int l = 0; l < v[j].size(); ++l) {
            print(v[j].at(l), (a[l]+1-v[j].at(l).length()));
        }
        cout << endl;
    }
    return 0;
}
