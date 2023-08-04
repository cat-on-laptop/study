#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> bigger;
priority_queue<int, vector<int>, greater<int>> smaller;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; 
    int temp, mid;
    cin >> temp;
    bigger.push(temp);
    cout << bigger.top() << endl;
    // bigger가 samller 보다 하나 더 많거나 사이즈가 같도록
    for(int i = 1; i < n; ++i){
        mid = bigger.top();
        cin >> temp;
        if(temp > mid){
            // smaller에 넣어야 함
            if(bigger.size() == smaller.size()){
                smaller.push(temp);
                bigger.push(smaller.top()); smaller.pop();
            }
            else{
                smaller.push(temp);
            }
        }
        else{
            // bigger에 넣어야 함
            if(bigger.size() == smaller.size()){
                bigger.push(temp);
            }
            else{
                bigger.push(temp);
                smaller.push(bigger.top()); bigger.pop();
            }
        }
        cout << bigger.top() << endl;
    }

    return 0;
}