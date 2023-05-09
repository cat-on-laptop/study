#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int A[200000], B[200000];
int a, b, cnt;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    for(int i = 0; i < a; ++i) cin >> A[i];
    for(int i = 0; i < b; ++i) cin >> B[i];

    sort(A, A + a), sort(B, B + b);

    for(int i = 0; i < a; ++i) if(!binary_search(B, B + b, A[i])) ++cnt;
    for(int i = 0; i < b; ++i) if(!binary_search(A, A + a, B[i])) ++cnt;

    cout << cnt << endl;
}