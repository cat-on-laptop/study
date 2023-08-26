#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

int n;

struct node_t{
    char val;
    int left, right;

    node_t(char _val = '\0', int _left = 0, int _right = 0) : val(_val), left(_left), right(_right) {}
};

node_t arr[105];

void input() {
    memset(arr, 0, sizeof(arr));
    cin >> n;
    int num;

    
    for(int i = 0; i < n; ++i) {
        cin >> num;
        cin >> arr[num].val;

        if((num << 1) + 1 <= n) cin >> arr[num].left >> arr[num].right;
        else if((num << 1) <= n) cin >> arr[num].left;
    }
}

void in_order(int curr = 1) {
    if(arr[curr].left) in_order(arr[curr].left);
    cout << arr[curr].val;
    if(arr[curr].right) in_order(arr[curr].right);
}


int main() {
    // freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0), cin.tie(0);
    for(int tc = 1; tc <= 10; ++tc) {
        input();
        cout << "#" << tc << ' ';
        in_order();
        cout << '\n';
    }
}