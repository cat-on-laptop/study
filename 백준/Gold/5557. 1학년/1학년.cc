#include <iostream>

using namespace std;
typedef long long ll;

ll arr[100][21];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, num; 
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        cin >> num;
        if(i == 0) arr[i][num] = 1;
        else{
            for(int j = 0; j <= 20; ++j){
                if(arr[i - 1][j]){
                    if(0 <= j + num && j + num <= 20) arr[i][j+num] += arr[i-1][j];
                    if(0 <= j - num && j - num <= 20) arr[i][j-num] += arr[i-1][j];
                }
            }
        }
    }
    cin >> num;
    
    cout << arr[n-2][num] << endl;
    return 0;
}