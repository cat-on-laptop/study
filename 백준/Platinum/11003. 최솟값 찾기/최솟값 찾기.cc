#include <iostream>
#include <deque>

using std::deque;
using std::pair;
using std::cin;
using std::cout;

int main() {
    // freopen("input.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, x; cin >> n >> l;

    deque<pair<int,int>> dq;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (!dq.empty() && dq.front().second == i - l) // 나갈 놈이면 out
            dq.pop_front();

        while (!dq.empty() && dq.back().first > x) // 내 앞 인덱스인데 나보다 크다? 가망x
            dq.pop_back();

        dq.push_back({x, i}); // dq는 단조 증가하는 순으로 되어 있음
        cout << dq.front().first << ' ';
    }
    return 0;
}