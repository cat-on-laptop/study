#include <iostream>
#define MAX 1'000'005
using namespace std;

int parent[MAX], n, m;

int find(int a){
    // 결국 타고 올라가는 건 find니 find에서 경로 압축
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    // a를 b로
    int pA = find(a), pB = find(b);
    parent[pA] = pB;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i <= n; ++i) parent[i] = i;
    int op, a, b;
    for(int i = 0; i < m; ++i){
        cin >> op >> a >> b;
        if(op){
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            Union(a, b);
        }
    }
    return 0;
}
