#include <algorithm>
#include <iostream>

using namespace std;

int n;
int arr[500005];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(register int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int q; cin >> q;
	for(register int i = 0; i < q; ++i){
		int x; cin >> x;
		cout << upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x) << ' ';
	}
	return 0;
}