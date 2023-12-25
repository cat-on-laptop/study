#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::queue;

vector<int> arr[100'005];
int parent[100'005];

int main() {
    // freopen("input.in", "r", stdin);
    std::ios::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    int x, y;

    for(int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        arr[x].emplace_back(y);
        arr[y].emplace_back(x);
    }

    parent[1] = 1;
    queue<int> q; q.emplace(1);

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        for(const int & c : arr[curr]) {
            if(parent[c]) continue;
            parent[c] = curr;
            q.emplace(c);
        }
    }

    for(int i = 2; i <= n; ++i) 
        cout << parent[i] << '\n';

    return 0;
}