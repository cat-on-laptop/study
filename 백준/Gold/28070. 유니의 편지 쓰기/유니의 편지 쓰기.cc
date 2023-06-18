#include <iostream>
#define endl '\n'

using namespace std;

int n;
int imos[10000][13];
int y, m, ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        char buff; int x, y, z, w;
        cin >> x >> buff >> y  >> z >> buff >> w;
        ++imos[x][y];
        if(w == 12) --imos[z+1][1];
        else --imos[z][w+1];
    }

    for(int i = 2000; i <= 9999; ++i) {
        for(int j = 0; j <= 12; ++j) {
            if(j == 0) imos[i][j] += imos[i-1][12];
            else imos[i][j] += imos[i][j-1];
        }
    }
    
    for(int i = 2000; i <= 9999; ++i) 
        for(int j = 0; j <= 12; ++j) {
            if(ans < imos[i][j]) {
                y = i, m = j, ans = imos[i][j];
            }
        }

    cout << y << '-';
    if(m < 10) cout << 0;
    cout << m << endl;
}