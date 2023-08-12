#include <cstdio>
#include <list>

using std::list;
using std::advance;

void print(list<int> &li) {
    auto it = li.begin();
    for(int i = 0; i < 10; ++i, ++it) {
        printf(" %d", *it);
    }
    puts("");
}

int main() {
    // freopen("input.txt" , "r", stdin);
    // freopen("output.txt", "w", stdout);

    for(int tc = 1; tc <= 10; ++tc) {
        list<int> arr;

        int n, m, idx, y, val; 
        char op;
        list<int>::iterator iter;
        // initialize list
        scanf("%d", &n);
        for(int i = 0;i < n; ++i) {
            scanf("%d", &val); 
            arr.emplace_back(val);
        }

        // processing
        scanf("%d", &m);

        for(int i = 0; i < m; ++i) {
            scanf(" %c", &op);
            
            if(op == 'I') {    
                scanf("%d %d", &idx, &y);  // 첫 번째 위치로부터 idx번째 위치에 y개의 값들을 삽입
                iter = arr.begin();
                advance(iter, idx);
                for(int i = 0; i < y; ++i) {
                    scanf("%d", &val);
                    arr.insert(iter, val);
                }
            }
            else if(op == 'D') {
                scanf("%d %d", &idx, &y);
                iter = arr.begin();
                advance(iter, idx);
                for(int i = 0; i < y; ++i)
                    iter = arr.erase(iter);
            }
            else {
                scanf("%d", &y);
                for(int i = 0; i < y; ++i) {
                    scanf("%d", &val);
                    arr.emplace_back(val);
                }
            }
        }

        printf("#%d", tc);
        print(arr);
    }
}