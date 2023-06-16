#include <iostream>
#include <vector>
#define MAX 55

using namespace std;

int parent[MAX], n, m, t;
vector<int> truth, party[MAX];

int find(int x ) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x), py = find(y);

    if(px == py) return;

    // y의 부모를 x로

    parent[py] = px;
}

int main() {
    cin >> n >> m >> t;

    for(int i = 1; i <= n; ++i) parent[i] = i;

    for(int i = 0; i < t; ++i) {
        int temp; cin >> temp;
        truth.push_back(temp);
    }
    
    for(int i = 1; i <= m; ++i) {
        int num, x; cin >> num;
        for(int j = 0; j < num; ++j) {
            cin >> x; party[i].push_back(x);

            if(j == 0) continue;
            merge(party[i][0], x);
            
        }
    }
    

    int ans = m;
    
    for(int i = 1; i <= m; ++i) {
        bool flag = false;
        for(const int &x : party[i]) {
            if(flag) continue;

            for(const int &y : truth) {
                if(find(y) == find(x)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) --ans;
    }

    cout << ans << endl;

    return 0;
}