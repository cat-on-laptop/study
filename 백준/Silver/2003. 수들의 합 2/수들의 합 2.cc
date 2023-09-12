#include <iostream>
#define MAX 10005
using namespace std;

int arr[MAX];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    int l, r, sum, cnt; 
    cnt = sum = l = r = 0;
    sum = arr[0];
    while(l < n && r < n){
        if(sum == m){
            ++cnt;
            sum+=arr[++r];
        }
        else if(sum < m){
            sum += arr[++r];
        }
        else{
            sum -= arr[l++];
        }
    }
    cout << cnt << '\n';
}