#include <iostream>
#include <string>

using namespace std;

bool f(int x){
    string xs = to_string(x);
    int d;
    if(xs.size()==1)
        return true;
    else {
        d = xs[1] - xs[0];
        for(int i =0;i<xs.size()-1;i++){
            if(xs[i+1]-xs[i] != d)
                return false;
        }
        return true;
    }
}

int main(void){
    int N,cnt=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        if(f(i))
            cnt++;
    }
    cout << cnt<<endl;
    return 0;
}