// 백준 2075

#include <iostream>
#include <queue>

using namespace std;

int n, temp;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    
    // input
    cin >> n;
    for(int i = 0; i < n * n; ++i){
        cin >> temp; pq.push(temp);
        if(pq.size() > n) pq.pop();
    }

    cout << pq.top() << endl;
}