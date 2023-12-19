#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::queue;
using std::vector;

int n;
char s[500'005];
char ans[500'005];
vector<int> arr[500'005];
bool visited[500'005];

void solution() {
    // init
    int idx = 0;
    visited[0] = true; ans[idx++] = s[0];
    queue<int> q; q.push(0);

    while(!q.empty()) {
        // q에 있는 건 모두 depth가 같은 node 이므로 같은 candidate..
        queue<int> candidate;
        char temp = '\0'; // 마지막 글자를 null로 하기 위해

        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(const int &x : arr[curr]) {
                if(visited[x] || temp > s[x]) continue;

                if(temp < s[x]) {
                    while(!candidate.empty()) candidate.pop();
                    temp = s[x];
                }
                candidate.push(x);
            }
        }

        ans[idx++] = temp;
        while(!candidate.empty()) {
            int curr = candidate.front(); candidate.pop();
            q.push(curr); visited[curr] = true;
        }
        
    }
}

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    // input
    cin >> n >> s;
    int x, y;
    for(int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x; --y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    solution();
    cout << ans;

    return 0;
}
