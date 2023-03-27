#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string> arr, ans;
int n, m;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		string temp; cin >> temp; arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int cnt = 0;
	for(int i = 0; i < m; ++i){
		string temp; cin >> temp;
		if(binary_search(arr.begin(), arr.end(), temp)){
			++cnt;
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << endl;
	for(const string &x : ans) cout << x << endl;
}