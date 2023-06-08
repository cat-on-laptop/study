#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool appear[27];

int main(int argc, char** argv){
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, rst = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		memset(appear, 0, sizeof(appear));
		string input;
		cin >> input;
		for(int j = 0; j < input.length(); ++j){
			if (appear[input[j]-'a']){
				// cout << input[j-1] << ' ' << input[j] <<endl;
				if(input[j-1] != input[j]) {
					// cout << input[j-1] << ' ' << input[j] <<endl;
					goto here;}
			}
			appear[input[j] - 'a'] = true;
		}
		++rst;
		// cout << rst << endl;
		here:;
	}
	cout << rst << endl;
}