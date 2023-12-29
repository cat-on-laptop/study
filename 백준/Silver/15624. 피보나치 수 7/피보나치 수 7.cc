#include <iostream>
#define endl '\n'
#define mod 1000000007
using namespace std;

class matrix{
    public:
    long long a, b, c, d;
    matrix(int _a = 1, int _b = 0, int _c = 0, int _d = 1){
        a = _a, b = _b, c = _c, d = _d;
    }

    matrix operator*= (const matrix &ref){
        long long tempA = (this->a * ref.a + this->b * ref.c) % mod;
        long long tempB = (this->a * ref.b + this->b * ref.d) % mod;
        long long tempC = (this->c * ref.a + this->d * ref.c) % mod;
        long long tempD = (this->c * ref.b + this->d * ref.d) % mod;
        this->a = tempA, this->b = tempB, this->c = tempC, this->d = tempD;
        return *this;
    }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;

    matrix fib(1, 1, 1, 0), rst;

    for(; n > 0; n = n >> 1){
        if(n & 1) rst *= fib;
        fib *= fib;
    }

    cout << rst.b << endl;
    
    return 0;
}