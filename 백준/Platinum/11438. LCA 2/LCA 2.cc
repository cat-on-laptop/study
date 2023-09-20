#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100'105
#define endl '\n'
using namespace std;

int n, m, a, b, parent[MAX][17], depth[MAX];
vector<int> G[MAX];
queue<int> q;

int lca(int x, int y){  
    // x가 더 깊음
    if(depth[x] < depth[y]) swap(x, y);

    for(int i = 16; i >= 0; --i){
        if(depth[x] - depth[y] >= (1 << i)){
            x = parent[x][i];
        }
    }

    if(x == y) return x;

    for(int i = 16; i >= 0; --i){
        if(parent[x][i] != parent[y][i]){
            x = parent[x][i], y = parent[y][i];
        }
    }
    return parent[x][0];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }

    // bfs
    q.push(1);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(const int & x : G[curr]){
            if(!depth[x] && x != 1){
                q.push(x);
                parent[x][0] = curr;
                depth[x] = depth[curr] + 1;
            }
        }
    }

    // sparse table
    for(int i = 1; i < 17; ++i){
        for(int j = 1; j <= n; ++j){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}