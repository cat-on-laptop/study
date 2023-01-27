// 백준 1976
// union - find 문제

#include <cstdio>

int n, m;
int parent[205], arr[1005];

int find(int x){
    // 타고 올라가서 반환
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    // x를 y아래로
    int px = find(x), py = find(y);
    parent[px] = py;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // input
    scanf("%d", &n); scanf("%d", &m);
    for(int i = 1; i <= n; ++i) parent[i] = i;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int temp; scanf("%d", &temp);
            // 두 도시를 왕복 할 수 있다면 같은 집합으로 예편
            if(temp) Union(i, j);
        }
    }

    for(int i = 0; i < m; ++i) scanf("%d", &arr[i]);
    bool flag = true;

    for(int i = 1; i < m; ++i){ 
        if(find(arr[i - 1]) != find(arr[i])){
            // 같은 집합이 아닌 도시다 -> 한번에 여행 할 수 없다.
            flag = false;
            break;
        }
    }
    
    flag ? puts("YES") : puts("NO");
}