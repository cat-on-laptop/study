#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int n, k, m;
vector<int>v[100001 * 2];
int visited[200002] = { 0, };

void bfs(int node) {
    queue<int>q;
    q.push(node);

    visited[node] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (visited[next] > 0)
                continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            v[num].push_back(n + i);
            v[n + i].push_back(num);
        }
    }
    bfs(1);
    if (visited[n] == 0)
        cout << -1;
    else
        cout << (visited[n] + 1) / 2;
}