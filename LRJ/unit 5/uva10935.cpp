#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int n;
    while (cin >> n && n){
        queue<int> q;
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        while (q.size() != 1){
            v.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "Discarded cards: ";
        for (int i = 0; i < v.size()-1; ++i) {
            cout << v.at(i) << " ";
        }
        cout << v.at(v.size()-1) << endl;
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
