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
        for(int i = 0; i < n - 1; ++i){
            cin >> temp >> buf;
            dq.push_back(temp);
        }

        if(n >= 1){
            cin >> temp; dq.push_back(temp);
        }
        cin >> buf;

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
            else {
                head = !head;
            }
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