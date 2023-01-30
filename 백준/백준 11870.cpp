// 백준 11870
// idea : 좌료를 받아서 정렬 후 중복을 없앰
// 이후 찾으려는 수를 이분 탐색하여 해당 idx 출력
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr, arr2;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int temp; cin >> temp;
        arr.push_back(temp);
        arr2.push_back(temp);
    }

    // 정렬 후 중복 값 제거
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    // 이분 탐색을 통해서 값의 idx를 출력하면 해당 원소가 몇 번째 크기의 원소인지 알 수 있음
    for(const int x: arr2){
        cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << ' ';
    }
}