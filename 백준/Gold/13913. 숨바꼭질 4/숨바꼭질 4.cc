#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using std::cin;
using std::cout;
using std::queue;
using std::stack;

int visited[100'005];
int prev[100'005];

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);
    memset(prev, -1, sizeof(prev));

    int n, k; cin >> n >> k;

    queue<int> q; visited[n] = 1; q.emplace(n);

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        if(curr == k) break;

        if(curr + 1 <= 100'000 && !visited[curr + 1]) {
            visited[curr + 1] = visited[curr] + 1;
            prev[curr + 1] = curr;
            q.emplace(curr + 1);
        } 

        if(curr-1 >= 0 && !visited[curr-1]) {
            visited[curr-1] = visited[curr]+1;
            prev[curr-1] = curr;
            q.emplace(curr-1);
        }

        if((curr << 1) <= 100'000 && !visited[curr << 1]) {
            visited[curr<<1]=visited[curr]+1;
            prev[curr<<1] =curr;
            q.emplace(curr << 1);
        }

    }

    cout << visited[k] - 1 << '\n';
    stack<int> st;
    
    int cnt = k;
    while(prev[cnt] >= 0) {
        st.emplace(cnt);
        cnt = prev[cnt];
    }

    cout << n << ' ';
    while(!st.empty()) {
        cout << st.top() << ' '; st.pop();
    }
}