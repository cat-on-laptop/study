#include <iostream>

using std::cin;
using std::cout;

int arr[1'000'005], score[1'000'005], visited[1'000'005], n;

int main () {
	std::ios::sync_with_stdio(0), cin.tie(0);

	// input
	cin >> n;
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	// process
	for(int i = 0; i < n; ++i) visited[arr[i]] = 1;

	for(int i = 0; i < n; ++i) {
		int curr = arr[i];
		for(int j = curr * 2; j <= 1'000'004; j += curr) {
			if(visited[j]) {
				++score[curr];
				--score[j];
			}
		}
	}

	for(int i = 0; i < n; ++i) cout << score[arr[i]] << ' ';

}