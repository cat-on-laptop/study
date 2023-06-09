#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans;

struct point {
    int x, y;

    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator< (const point &x) const {
        if(this->x == x.x) return this->y < x.y;
        return this->x < x.x;
    }

};

vector<point> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if(x > y) {
            int temp = x; x = y; y = temp;
        }
        arr.push_back(point(x, y));
    }

    sort(arr.begin(), arr.end());

    int left = -1000000005, right = -1000000005;

    for(const point &x : arr) {
        // 선분이 겹치는 경우 더 오른쪽이 right가 됨
        if(x.x < right) right = max(x.y, right);

        else {
            // 구간이 겹치지 않으니 지금까지의 구간 더하고
            // left right 의 초기 값은 차가 0이 되도록 설정
            ans += right - left;
            left = x.x; right = x.y;
        }
    }

    // 마지막 구간 더해줌
    ans += right - left;

    // output
    cout << ans; 
    
    return 0;
}