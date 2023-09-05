//#include <iostream>
//
//using std::cin;
//using std::cout;
//
//int arr[100005], n;
//
//inline int abs(int x) {
//	return x > 0 ? x : -x;
//}
//
//int main() {
//	std::ios::sync_with_stdio(0), cin.tie(0);
//	cin >> n;
//
//	for (int i = 0; i < n; ++i) cin >> arr[i];
//
//	int l = 0, r = n - 1;
//	int sum = arr[l] + arr[r];
//	int ans = abs(sum);
//	while (sum != 0 && l < r) {
//		if (sum > 0) r--;
//
//
//		else l++;
//
//		sum = arr[l] + arr[r];
//		ans
//	}
//}

#include <iostream>
#define MAX 1000005
using namespace std;
int N, K;
int Cables[MAX];

bool calc(long long len) {
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += Cables[i] / len;
        //cout << "cnt = " << cnt << endl;
        if (cnt >= K) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> Cables[i];
    }

    long long left = 0;
    long long right = 0x7fffffffffffffff;
    long long ans = 0;

    while (left <= right) {
        //int mid = (left + right) / 2;
        long long mid = left + (right - left) / 2;
        //cout << "mid = " << mid << endl;
        if (calc(mid)) {
            ans = mid;
            //cout << "ans = " << ans << endl;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}