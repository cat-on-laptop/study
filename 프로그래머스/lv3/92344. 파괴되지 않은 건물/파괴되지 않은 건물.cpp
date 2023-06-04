#include <string>
#include <vector>
#include <iostream>
using namespace std;

int imos[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(const vector<int> &x : skill) {
        if(x[0] == 1) { // type1 attack
            imos[x[1]][x[2]] -= x[5];
            imos[x[1]][x[4] + 1] += x[5];
            imos[x[3] + 1][x[2]] += x[5];
            imos[x[3] + 1][x[4] + 1] -= x[5];
        }
        else {
            imos[x[1]][x[2]] += x[5];
            imos[x[1]][x[4] + 1] -= x[5];
            imos[x[3] + 1][x[2]] -= x[5];
            imos[x[3] + 1][x[4] + 1] += x[5];
        }
    }
    
    int n = board.size();
    int m = board[0].size();
    
    for(int row = 0; row < n; ++row) { // 세로로 휩쓸기
        for(int col = 1; col < m; ++col) {
            imos[row][col] += imos[row][col - 1];
        }
    }
    
    for(int col = 0; col < m; ++col) {
        for(int row = 1; row < n; ++row) {
            imos[row][col] += imos[row - 1][col];
        }
    }
    
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            board[row][col] += imos[row][col];
            if(board[row][col] > 0) ++answer;
        }
    }
    
    
    return answer;
}