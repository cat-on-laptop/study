#include <cstdio>
#include <deque>

using std::deque;

struct data_t{
    int val, idx;

    data_t(int v, int i) : val(v), idx(i) {}
};

int arr[5'000'000];

int main() {
    // freopen("input.in", "r", stdin);
    int n, l; scanf("%d %d", &n, &l);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    deque<data_t> dq;

    for(int i = 0; i < n; ++i) {
        if(!dq.empty() && dq.front().idx == i - l) // 나갈 놈이면 out
            dq.pop_front();

        while(!dq.empty() && dq.back().val > arr[i]) // 내 앞 인덱스인데 나보다 크다? 가망x
            dq.pop_back();

        dq.emplace_back(arr[i],i); // dq는 단조 증가하는 순으로 되어 있음
        printf("%d ", dq.front().val);
    }
    return 0;
}