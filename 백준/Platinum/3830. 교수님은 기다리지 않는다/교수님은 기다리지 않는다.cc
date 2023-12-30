#include <cstdio>
#include <iostream>
#include <utility>
#define MAX 100'105
#define endl '\n'
using namespace std;
typedef long long ll;

pair<int, ll> parent[MAX]; 
int n, m;

pair<int, ll> find(int a){
    // a의 부모를 찾아 압축
    if(parent[a].first == a) return parent[a];
    pair<int, ll> temp = find(parent[a].first);
    return parent[a] = make_pair(temp.first, parent[a].second + temp.second);
}

void grp(int a, int b, ll diff){
    // a를 b의 집합으로 합치기
    pair<int, ll> pA = find(a);
    pair<int, ll> pB = find(b);
    parent[pA.first] = {pB.first, pB.second - pA.second + diff};
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    char op;
    int a, b, w;
    while (true){
        // scanf("%d %d", &n, &m);
        cin >> n >> m;
        if(!(n*m)) return 0;
        for(int i = 1; i <= n; ++i) parent[i] = {i, 0};
        for(int i = 0; i < m; ++i){
            // scanf("%c", &op);
            cin >> op;
            if(op == '!'){
                // scanf("%d %d %d", &a, &b, &w);
                cin >> a >> b >> w;
                grp(a, b, w);
            }
            else{
                // scanf("%d %d", &a, &b);
                cin >> a >> b;
                pair<int, ll> pa = find(a);
                pair<int, ll> pb = find(b);
                if(pa.first != pb.first) 
                    // puts("UNKNOWN");
                    cout << "UNKNOWN\n";
                else
                    // printf("%lld\n", pa.second - pb.second);
                    cout << pa.second - pb.second << endl;   
            }
        }
    }
    return 0;
}