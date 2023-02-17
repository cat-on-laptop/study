#include <iostream>
#include <set>

using namespace std;

set<int> prime;

bool isPrime(int x) {
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) return false;
    }

    return true;
}

bool isOk(int x) {
    while(x) {
        if(prime.find(x) == prime.end()) return false;
        x /= 10;
    }
    return true;
}

int n;

int main(void) {
    // make set
    for(int i = 2; i <= 99999999; ++i) {
        if (isPrime(i)) prime.insert(i);
    }
    cout << "done" << endl;
    // input
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    if(isOk(7331)) cout << 7331;

}