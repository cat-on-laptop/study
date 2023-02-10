#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 30

using namespace std;

int arr[MAX][MAX], n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> people;

bool visited[MAX][MAX];

bool inRange(int row, int col) {
    return 0 <= row && row < n && 0 <= col && col < n;
}

int dfs(int row, int col) {
    int cnt = 1;

    for(int d = 0; d < 4; ++d) {
        int nr = row + dir[d][0], nc = col + dir[d][1];
        if(inRange(nr, nc) && !visited[nr][nc] && arr[nr][nc]) {
            visited[nr][nc] = true;
            cnt += dfs(nr, nc);
        }
    }

    return cnt;
}

int main() {
    // input
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];

    // 각 격자점에 dfs하여 한번 dfs할 때마다 cnt를 +1 개 하여 마을의 수 파악
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(arr[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                ++cnt;
                people.push_back((i, j));
            }
        }
    }

    // 마을 인원 수를 크기 순으로 정렬
    sort(people.begin(), people.end());

    // output
    cout << cnt << endl;
    for(const int x : people) cout << x << endl;
}