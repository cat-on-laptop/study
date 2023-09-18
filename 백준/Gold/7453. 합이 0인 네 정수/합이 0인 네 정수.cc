#include <iostream>
#include <algorithm>
#define MAX 4005
#define endl '\n'
using namespace std;

int n;
int A[MAX], B[MAX], C[MAX], D[MAX];
int arr[MAX*MAX], arr2[MAX*MAX];

int upper(int s, int e, int target){
    int ans = e + 1;

    while(s <= e){
        int mid = (s + e) >> 1;
        if(arr2[mid] + target > 0){
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    return ans;
}

int lower(int s, int e, int target){
    int ans = e + 1;

    while(s <= e){
        int mid = (s + e) >> 1;
        if(arr2[mid] + target >= 0){
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int idx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            arr[idx] = A[i] + B[j];
            arr2[idx] = C[i] + D[j];
            ++idx;
        }
    }

    sort(arr, arr + n * n);
    sort(arr2, arr2 + n * n);

    long long cnt = 0;
    for(int i = 0; i < n * n; ++i){
        // int low = lower(0, n * n, arr[i]);
        // int up = upper(0, n * n, arr[i]);
        int low = lower_bound(arr2, arr2 + n*n, -arr[i]) - arr2;
        int up = upper_bound(arr2, arr2 + n * n, -arr[i]) - arr2;
        cnt += up - low;
    }
    cout << cnt << endl;
}