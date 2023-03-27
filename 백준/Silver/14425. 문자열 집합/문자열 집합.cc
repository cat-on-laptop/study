#include <iostream>
#include <map>
#include <string>
#define endl '\n'

using namespace std;

map<string, int> m;
int n, q;
string temp;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        m[temp] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < q; ++i){
        cin >> temp;
        if(m.find(temp) != m.end()) ++cnt;
    }
    cout << cnt << endl;
}