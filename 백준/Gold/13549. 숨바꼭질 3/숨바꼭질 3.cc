#include <iostream>
#include <deque>

using std::cin;
using std::cout;
using std::deque;

int visited[100'005];
int n, k;

int main () {
    cin >> n >> k;

    // 0 - 1 bfs
    deque<int> dq; dq.emplace_front(n); visited[n] = 1;

    while(!dq.empty()) {
        int curr = dq.front(); dq.pop_front();

        if(curr == k) break;

        if((curr << 1) <= 100'000 && !visited[curr << 1]) {
            // 순간이동은 가중치가 0
            dq.emplace_front(curr << 1);
            visited[curr << 1] = visited[curr];
        }

        if(curr > 0 && !visited[curr-1]) {
            dq.emplace_back(curr - 1);
            visited[curr-1] = visited[curr] + 1;
        }

        if(curr < 100'000 && !visited[curr+1]) {
            dq.emplace_back(curr + 1);
            visited[curr+1] = visited[curr] + 1;
        }
    }

    cout << visited[k] - 1;
}