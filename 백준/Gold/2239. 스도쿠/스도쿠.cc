#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#define endl '\n'
using namespace std;

int arr[9][9], cnt;
vector<pair<int, int>> pos;

bool check(int row, int col){
    int ROW = (row / 3)*3;
    int COL = (col / 3)*3;

    // 세로 줄 확인
    for(int i = 0; i < 9; ++i){
        if(i == row) continue;
        if(arr[i][col] == arr[row][col]) return false;
    }
    
    // 가로 줄 확인
    for(int i = 0; i < 9; ++i){
        if(i == col) continue;
        if(arr[row][i] == arr[row][col]) return false;
    }

    // 작은 사각형 확인
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(ROW + i == row && COL + j == col) continue;
            if(arr[ROW + i][COL + j] == arr[row][col]) return false;
        }
    }

    return true;
}


void backtrack(int curr){
    if(curr == cnt){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j) cout << arr[i][j];
            cout << endl; 
        }
        exit(0);
    }
    int row = pos[curr].first, col = pos[curr].second;
    for(int i = 1; i <= 9; ++i){
        arr[row][col] = i;
        if(check(row, col)) backtrack(curr + 1);
        arr[row][col] = 0;
    }   
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    for(int i = 0; i < 9; ++i){
		string x; cin >> x;
        for(int j = 0; j < 9; ++j){
            arr[i][j] = x[j] - '0';
            if(!arr[i][j]){
                pos.push_back(make_pair(i,j));
                ++cnt;
            }
        }
    }
    backtrack(0);
    return 0;
}