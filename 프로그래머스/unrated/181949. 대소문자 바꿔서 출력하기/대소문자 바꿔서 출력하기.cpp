#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char &x : str) 
        if('A' <= x && x <= 'Z') x += 32;
        else x -= 32;
    cout << str;
    
    return 0;
}