//                     _ooOoo_
//                    o8888888o
//                    88" . "88
//                    (| -_- |)
//                    O\  =  /O
//                 ____/`---'\____
//               .'  \\|     |//  `.
//              /  \\|||  :  |||//  \
//             /  _||||| -:- |||||-  \
//             |   | \\\  -  /// |   |
//             | \_|  ''\---/''  |   |
//             \  .-\__  `-`  ___/-. /
//           ___`. .'  /--.--\  `. . __
//        ."" '<  `.___\_<|>_/___.'  >'"".
//       | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//       \  \ `-.   \_ __\ /__ _/   .-` /  /
//  ======`-.____`-.___\_____/___.-`____.-'======
//                     `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//               Buddha Bless, No Bug !

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr1, arr2;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr1.push_back(x);
    }
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr2.push_back(x);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < n; ++i) ans += arr1[i] * arr2[i];
    cout << ans << endl;
}