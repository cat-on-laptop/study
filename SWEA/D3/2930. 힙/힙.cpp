#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        cin >> n;
        cout << "#" << tc << " ";
        pq = priority_queue<int>();
        int x;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            if(x & 1) {
                cin >> x;
                pq.push(x);
            }
            else {
                if(!pq.empty()) {
                    cout << pq.top() << ' ';
                    pq.pop();
                }
                else cout << "-1 ";
            }
        }
        cout << '\n';
    }
}