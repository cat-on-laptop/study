#include <iostream>
#define MAX 1024
#define endl '\n'
using namespace std;

typedef long long ll;

ll tree[(MAX*MAX) << 1];
int n, m, k;
int tempN;

void update(int idx, ll val){
    idx = idx + tempN - 1;
    tree[idx] = val;
    idx = idx >> 1;
    while(idx >= 1){
        tree[idx] = tree[idx << 1] + tree[(idx << 1) + 1];
        idx = idx >> 1;
    }
}

ll sum(int a, int b){
    ll val = 0;
    a = a + tempN - 1;
    b = b + tempN - 1;
    while(a <= b){
        if(a & 1) val += tree[a];
        if(!(b & 1)) val += tree[b];
        a = (a + 1) >> 1;
        b = (b - 1) >> 1;
    }
    return val;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;

    // n 이상인 2의 거듭제곱 tempN 
    for(tempN = 1; tempN < n; tempN  = tempN << 1);
    
    for(int i = 0; i < n; ++i) cin >> tree[tempN + i];
    for(int i = tempN - 1; i >= 1; --i) tree[i] = tree[i << 1] + tree[(i << 1) + 1];

    int a, b;
    ll c;
    m += k;
    for(int q = 0; q < m; ++q){
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else{
            cout << sum(b, c) << endl;
        }
    }

    return 0;
}