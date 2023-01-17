// 백준 11286

#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

inline int abs(int x){
    return x >= 0 ? x : -x;
}

struct cmp{
    bool operator()(const pair<int, int>&x, const pair<int, int> &y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        else return x.first > y.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int n, op;

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> op; 
        if(op){
            pq.push(make_pair(abs(op), op));
        }
        else{
            if(pq.empty()) cout << 0 << endl;
            else{
                pair<int, int> curr = pq.top(); pq.pop();
                cout << curr.second << endl;
            }
        }
    }
}