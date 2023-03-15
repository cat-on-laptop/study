#include <cstdio>

int n;

bool prime(int n) {
    if (n < 2) return false;

    while(n) {
        for(int i = 2; i <= n / i; ++i) {
            if(n % i ==0) return false;
        }
        n /= 10;
    }
    return true;
}

void backtracking(int curr, int num) {
    // 현재까지 선택한 자리수 curr과 선택한 수 num이 주어지면
    // 숫자를 만들고 n자리가 되었을 때 신기한 소수가 되면 출력하는 함수
    if(curr == n) {
        printf("%d\n", num);
        return;
    }

    for(int i = 0; i < 10; ++i) {
        if(prime(num * 10 + i)) backtracking(curr + 1, num * 10 + i);
    }
    

}

int main() {
    // input
    scanf("%d", &n);

    // backtracking
    backtracking(0, 0);

    return 0;
}