#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int x, y, z;
    while(true){
        cin >> x >> y >> z;
        if(!x && !y && !z) break;
        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }    
        if(y > z){
            int temp = y;
            y = z;
            z = temp;
        }
        if(z*z == x*x + y*y) cout << "right\n";
        else cout << "wrong\n";
    }    

    return 0;
}