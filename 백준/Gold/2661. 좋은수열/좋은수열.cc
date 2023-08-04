#include <iostream>

using namespace std;

int arr[100];
int n;
bool flag = false;

bool valid(int idx) {
    for (int cnt = 0; cnt < ((idx + 1) >> 1); ++cnt) {
        bool flag = true;
        // 일단 나쁜 수열이라 가정 후 다른 게 나오면 false를 통해 좋은 수열이라 판단

        for (int i = 0; i < cnt + 1; ++i) {
            if (arr[idx - i] != arr[idx - i - (cnt + 1)]) flag = false;
            // cout << '\t' << "idx - i : " << idx - i << " idx - i - ((cnt+1) <<1) : " << idx - i - (cnt + 1) << endl;
        }

        // 나쁜 수열이면 false 리턴
        if (flag) return false;
    }

    // 통과했으니 true 리턴
    return true;
}

void f(int curr) {
    if (flag) return;
    if (curr == n) {
        for (int i = 0; i < n; ++i) cout << arr[i];
        flag = true;
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        arr[curr] = i;
        if(valid(curr)) f(curr + 1);
    }
}



int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;
    f(0);
}