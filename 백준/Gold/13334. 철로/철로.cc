#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;
using std::sort;

struct edge_t {
    int s, e;

    edge_t(int _s, int _e) : s(_s), e(_e) {}

    bool operator<(const edge_t &x) const {
        if (s > x.s) return true;
        if (s < x.s) return false;

        // 끝점을 기준으로 정렬할 것이므로 pq에도 끝 점이 먼저 끝나는 순으로 정렬되어야 함
        if (e > x.e) return true;
        if (e < x.e) return false;

        return false;
    }
};

bool cmp(const edge_t &l, const edge_t &r) {
    if (l.e < r.e) return true;
    if (l.e > r.e) return false;

    if (l.s < r.s) return true;
    if (l.s > r.s) return false;

    return false;
}

inline int max(int x, int y) {
    return x > y ? x : y;
}

vector<edge_t> arr;
priority_queue<edge_t> pq;
int n, k;

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // input & preprocess
    cin >> n; 
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if(x < y) arr.emplace_back(x, y);
        else arr.emplace_back(y, x);
    }
    cin >> k;
    sort(arr.begin(), arr.end(), cmp);

    int cnt = 0;

    for(const edge_t &edge : arr) {
        int s = edge.s, e = edge.e;

        if(e - s <= k)  // 구간의 크기가 k 이하라면 들어갈 수 o
            pq.emplace(edge);
        else continue;

        while(!pq.empty() && e - pq.top().s > k) // e와 pq의 맨 처음에 있는 구간의 시점까지의 거리가 k 초과면 구간 벗어남
            pq.pop();

        cnt = max(cnt, pq.size());
    }

    cout << cnt;
}