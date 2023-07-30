#include <cstdio>
#include <cstring>
#define MAX 25

int D, W, K, ans; // D := 줄 수, W := 가로 길이, K := 합격 기준, ans := 정답
int arr[MAX][MAX];
// int arr[6][8] = {
//         0, 0, 1, 0, 1, 0, 0, 1, 
//         0, 1, 0, 0, 0, 1, 1, 1,
//         0, 0, 0, 0, 0, 0, 0, 0, 
//         1, 1, 1, 1, 0, 0, 0, 1, 
//         0, 1, 1, 0, 1, 0, 0, 1, 
//         1, 1, 1, 1, 1, 1, 1, 1 
// };


inline int min(int x, int y) {
    return x < y ? x : y;
}

void init() {
    // reset variables 
    ans = 0x7fffffff;
}

void input() {
    scanf("%d %d %d", &D, &W, &K);

    for(int i = 0; i < D; ++i) 
        for(int j = 0; j < W; ++j) 
            scanf("%d", &arr[i][j]);
        
}

bool is_valid(int col) {
    // 해당 col이 유효한지를 리턴
    for(int i = 0; i + K - 1 < D; ++i) {
        bool flag = true;
        for(int j = 1; j < K; ++j) 
            if(arr[i][col] != arr[i+j][col]) {
                flag = false;
                break;
            }
        if(flag) return true;
    }
    return false;
}

void process(int row, int val) {
    // row행을 val로 처리하는 함수

    for(int i = 0; i < W; ++i) 
        arr[row][i] = val;
}

void print();

void backtracking(int curr, int cnt) {
    // backtracking하여 최소값을 갱신하는 함수
    // curr := 현재 처리하는 row, cnt := 현재까지 약품 투입 횟수

    if(cnt >= ans) return;

    if(curr == D) {
        for(int col = 0; col < W; ++col)
            if(!is_valid(col)) return;
            
        ans = cnt;
        return;
    }

    // 처리 x
    backtracking(curr + 1, cnt);

    // 처리 전 정보 저장을 위한 배열 prev;
    int prev[MAX]; 
    memcpy(prev, arr[curr], sizeof(prev));

    // 1로 처리
    process(curr, 1);
    backtracking(curr + 1, cnt + 1);

    // 0으로 처리
    process(curr, 0);
    backtracking(curr+1, cnt + 1);

    // 이전 상태로 배열 되돌리기
    memcpy(arr[curr], prev, sizeof(prev));

}

void print() {
    for(int i = 0; i < D; ++i) {
        for(int j = 0; j < W; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    puts("");
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc) {
        init();
        input();
        backtracking(0, 0);

        printf("#%d %d\n", tc, ans);
    }
}