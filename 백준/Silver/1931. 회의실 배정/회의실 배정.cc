#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
  if(x.second == y.second) return x.first < y.first;
  return x.second < y.second;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    arr.push_back({x, y});
  }
  sort(arr.begin(), arr.end(), cmp);
  
  int cnt = 1; 
  int et = arr[0].second;
  for(int i = 1; i < n; ++i) {
    if(arr[i].first < et) continue;
    
    et = arr[i].second;
    ++cnt;
  }
  
  cout << cnt;
}