#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, cnt;

int main(int argc, char **argv) {
    ios::sync_with_stdio(0), cin.tie(0);
    // input
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        pq.push(temp);
    }

    // 최솟값을 기준으로 횟수를 더하면 됨
    if(pq.size() == 1) {
        cout << 0;
        return 0;
    }

    while(pq.size() >= 2) {
        int x, y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();

        cnt += x + y;
        pq.push(x + y);

    }

    cout << cnt;

    return 0;
}