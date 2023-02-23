// 백준 1697
// main idea : 한 상태를 노드로 보고 다른 상태로 가는걸 층별로 봐야하니 bfs

#include <iostream>
#include <queue>
#define offset 20000000

using namespace std;

int n, k, ans;

bool visited[40000005];

void bfs(void){
    queue<pair<int, int>> q;
    q.push({n, 0});

    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();

        if(curr.first == k){
            ans = curr.second; break;
        }
        // cout << "curr " << curr.first;
        // + 1
        int n1 = curr.first + 1, n2 = curr.first - 1, n3 = curr.first << 1;
        // cout << " n1 " << n1 << " n2 " << n2 << " n3 " << n3 << endl; 
        if(n1 == k || n2 == k || n3 == k){
            ans = curr.second + 1; break;
        }
        if(n1 < offset && !visited[n1 + offset]){
            visited[n1 + offset] = true; q.push({n1, curr.second + 1}); 
        }
        if(n2 < offset && !visited[n2 + offset]){
            visited[n2 + offset] = true; q.push({n2, curr.second + 1});
        }
        if(n3 < offset && !visited[n3 + offset]){
            visited[n3 + offset] = true; q.push({n3, curr.second + 1});
        }
    }
}

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    
    // input
    cin >> n >> k;

    visited[n + offset] = true;
    bfs();

    cout << ans << endl;
}