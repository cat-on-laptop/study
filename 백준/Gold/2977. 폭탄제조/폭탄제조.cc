#include <iostream>
#define MAX 105

using std::cin;
using std::cout;

int n, m, k;
int part[MAX], have[MAX], sk[MAX], sp[MAX], bk[MAX], bp[MAX]; 
// part[i] := i번째 부품의 필요 수, have[i] := i번째 부품 보유 수
// sk[i] := i 번째 부품이 소형 세트에 몇개 있는지, sp[i] := i번째 소형 세트의 가격
// bk[i] := i 번째 부품이 대형 세트에 몇개 있는지, bp[i] := i번째 대형 세트의 가격
// 개수를 기준으로 bs

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> part[i] >> have[i] >> sk[i] >> sp[i] >> bk[i] >> bp[i];
    }
    
}

inline int min(int x, int y) {
    return x < y ? x : y;
}

bool valid(int x) {
    int tot = 0; // 총 가격의 개수
    for(int i = 0; i < n; ++i) {
        int need = part[i]*x - have[i];
        int money = 0x7fffffff;
        if(need <= 0) continue; // 이미 필요 부품을 가진 경우 pass
        
        // 작은 걸 기준으로 셈
        
        int iter = need / sk[i]; 
        if(need % sk[i]) ++iter;

        for(int p = 0; p <= iter; ++p) {
            int need2 = need - p*sk[i];

            int b = need2 <= 0 ? 0 : need2 / bk[i];
            (need2 > 0) && (need2 % bk[i]) ? ++b : b;

            // printf("작은거 : %d개, 큰거 : %d개, 가격 :%d\n",p,b,p*sp[i] + b*bp[i]);
            money = min(money, p*sp[i] + b*bp[i]);
        }
        
        tot += money;
    }
    return tot <= m;
}


void process() {
    int l = 0, r = m, _m, ans = m;

    while (l <= r) {
        _m = l + ((r - l) >> 1);
        if (valid(_m)) {
            // 가능하면 더 만들 수 있도록
            ans = _m;
            l = _m + 1;
        }
        // 불가능하면 덜 만들게
        else r = _m -1;
    }
    cout << ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    input();
    process();
    
}