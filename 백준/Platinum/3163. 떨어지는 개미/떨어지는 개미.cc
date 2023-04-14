/* 알고리즘: 개미의 경우 좌우의 끝에 있는 개미부터 떨어 질 수 있다.
        충돌을 고려하지 않고 개미가 떨어지는 순서와 시간을 계산한 결과와
        충돌을 고려하고 개미가 떨어지는 순서와 시간을 계산한 결과는 동일하며
        떨어지는 개미의 id만 바뀐다. 위에서 서술하였듯 개미는 좌우의 끝에 있는
        개미부터 떨어질 수 있으므로 낙하하는 시간을 기준으로 정렬한 후
        낙하하는 위치에 따라 좌에서 혹은 우에서 개미의 id를 선택하면 된다.*/

#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, l, k, t;
int id[100005];

struct ant_t {
    int pos, id;
    ant_t() : pos(0x7fffffff), id(0) {}
    ant_t(int _pos, int _id) : pos(_pos), id(_id) {}

    bool operator<(const ant_t & x) const {
        // 충돌 x 떨어지는 순서대로 정렬
        // int d1 = this->id > 0 ? l - this->pos : this->pos;
        // int d2 = x.id > 0 ? l - x.pos : x.pos;
        if(this->pos == x.pos) {
            return this->id < x.id;
        }
        return this->pos < x.pos;
    }
};

ant_t arr[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> t;

    while(t--) {

        cin >> n >> l >> k;
        for(int i = 0; i < n; ++i) {
            int pos, id; cin >> pos >> id;
            if(id > 0) pos = l - pos;
            arr[i] = ant_t(pos, id); ::id[i] = id;
        }
        sort(arr, arr + n);
        int left = 0, right = n - 1;
        for(int i = 0; i < n; ++i) {
            if(arr[i].id > 0) arr[i].id = ::id[right--];
            else arr[i].id = ::id[left++];
        }
        sort(arr, arr + n);
        cout << arr[k-1].id << endl;
    }

    return 0;
}