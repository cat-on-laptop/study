#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

string command;
int x, n, flag;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> command;
        if(command == "add"){
            cin >> x;
            flag |= (1 << x);
        }
        else if(command == "remove"){
            cin >> x;
            flag &= ~(1 << x);
        }
        else if(command == "check"){
            cin >> x;
            if((flag & (1 << x))) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(command == "toggle"){
            cin >> x;
            flag ^= (1 << x);
        }
        else if(command == "all") flag = 0b111111111111111111111;
        else flag = 0;
    }
}