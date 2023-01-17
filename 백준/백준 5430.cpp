// 백준 5430

#include <iostream>
#include <string>
#include <deque>
#include <cctype>
#define endl '\n'

using namespace std;

string op;
int t, n;
deque<int> dq;

int main(void){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    // input
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        // init
        int temp; char buf; dq = {};
        cin >> op >> n >> buf;
        bool head = true; // head가 true이면 앞이 처음 false 면 뒤가 처음
        bool flag = true; // flag가 true이면 error x

        // input 
        // [1,2,3,4,5] -> 처음 [는 op, n과 함께 받으면서 buf로 날림
        for(int i = 0; i < n - 1; ++i){
            cin >> temp >> buf;
            dq.push_back(temp);
        }
        // n - 1개는 숫자, 의 형태이므로 buf를 통해 날려버리고
        if(n >= 1){
            cin >> temp; dq.push_back(temp);
        }
        // n이 1 이상이면 마지막 숫자가 있으므로 받아주고
        cin >> buf; 
        // 마지막 ]도 buf로 날림

        for(const char &x : op){
            if(x == 'D'){
                if(dq.empty()){
                    flag = false;
                    break;
                }
                else{
                    if(head) dq.pop_front();
                    else dq.pop_back();
                }
            }
            else head = !head;
        }

        if(flag){
            cout << '[';
            if(head){
                for(deque<int>::iterator iter = dq.begin(); iter != dq.end(); ++iter){
                    cout << *iter;
                    if(iter != dq.end() - 1) cout << ',';
                }
            }
            else{
                for(deque<int>::reverse_iterator iter = dq.rbegin(); iter != dq.rend(); ++iter){
                    cout << *iter;
                    if(iter != dq.rend() - 1) cout << ',';
                }
            }
            cout << ']' << endl;
        }
        else cout << "error" << endl;
    }

    return 0;
}