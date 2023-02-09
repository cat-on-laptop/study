#include <iostream>
#define MAX 55

using namespace std;

int n, m, t;
int mapper[128];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상 하 좌 우

struct marble {
    int num, weight;
    char dir;
    marble() : num(-1), weight(-1), dir('X') {}
    marble(int _num, int _weight, char _dir) : num(_num), weight(_weight), dir(_dir) {}

    const bool operator>(const marble &x) const {
        return this->num > x.num;
    }

    const bool operator==(const marble &x) const {
        return this->num == x.num && this->dir == x.dir && this->weight == x.weight;
    }

    const bool operator!=(const marble &x) const {
        return this->num != x.num || this->dir != x.dir || this->weight != x.weight;
    }
};

bool inRange(int row, int col) {
    return 0 <= row && row < n && 0 <= col && col < n;
}

marble arr[MAX][MAX], temp[MAX][MAX];
const marble none(-1, -1, 'X'); // 비었음을 표시하기 위한 상수

void reset() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            temp[i][j] = none;
        }
    }
}

char flip(char d) {
    // 방향을 반대 방향으로 전환
    if(d == 'U') return 'D';
    if(d == 'D') return 'U';
    if(d == 'L') return 'R';
    if(d == 'R') return 'L';
}

void simulate() {
    // 시뮬레이션 하기 전에 temp 배열을 초기화
    reset();

    // 구슬들을 진행시킴
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            if(arr[i][j] != none) {
                int d = mapper[arr[i][j].dir];
                int nr = i + dir[d][0], nc = j + dir[d][1];

                if (!inRange(nr, nc)) {
                    // 범위를 벗어나고 temp가 비어있는 경우 방향만 반대로
                    if(temp[i][j] == none) temp[i][j] = marble(arr[i][j].num, arr[i][j].weight, flip(arr[i][j].dir));

                    else {
                        // 범위를 벗어나고 temp가 차 있는 경우 번호가 큰 구슬의 번호와 방향을 temp로
                        if (temp[i][j] > arr[i][j]) {
                            temp[i][j] = marble(temp[j][i].num, temp[i][j].weight + arr[i][j].weight, temp[i][j].dir);
                        }
                        else {
                            temp[i][j] = marble(arr[i][j].num, temp[i][j].weight + arr[i][j].weight, flip(arr[i][j].dir));
                        }
                    }
                }
                  
                else {
                    // 새로 가는 위치가 범위를 벗어나지 않고 
                    // 해당 위치가 차있다면 더 번호가 큰 구슬의 방향, 번호, 두 무게의 합으로 해당 위치를 재정의
                    if(temp[nr][nc] != none) {
                        if (temp[nr][nc] > arr[i][j]) {
                            temp[nr][nc] = marble(temp[nr][nc].num, temp[nr][nc].weight + arr[i][j].weight, temp[nr][nc].dir);
                        }
                        else {
                            temp[nr][nc] = marble(arr[i][j].num, temp[nr][nc].weight + arr[i][j].weight, arr[i][j].dir);
                        }
                    }
                    else temp[nr][nc] = arr[i][j];
                }
            }
        }
    }

    // temp 배열에 저장한 구슬들을 다시 arr로 옮김
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j)
            arr[i][j] = temp[i][j];
}

void print(){
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (arr[i][j] == none) cout << "none ";
            else cout << "<#" << arr[i][j].num << ", " << arr[i][j].weight << ", " << arr[i][j].dir << "> ";
        }
        cout << endl;
    }
}

int main() {
    mapper['U'] = 0, mapper['D'] = 1, mapper['L'] = 2, mapper['R'] = 3;
    cin >> n >> m >> t;

    for(int i = 0; i < m; ++i) {
        int row, col, weight; char dir;
        cin >> row >> col >> dir >> weight;
        row -= 1, col -= 1;
        arr[row][col] = marble(i + 1, weight, dir);
    }

    // print();
    // cout << endl;
    for(int i = 0; i < t; ++i) {
        // simulate
        simulate();
        // print();
        // cout << endl;
    }

    int cnt = 0, val = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (arr[i][j] != none) {
                ++cnt;
                val = max(val, arr[i][j].weight);
            }
        }
    }
    cout << cnt << " " << val << endl;
}