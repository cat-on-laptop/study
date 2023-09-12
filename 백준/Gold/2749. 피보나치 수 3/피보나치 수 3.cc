#include <iostream>
#define MOD 1000000
using namespace std;

class matrix{
    public:
    unsigned long long a, b, c, d;
    matrix (int _a = 1, int _b = 0, int _c = 0, int _d = 1){
        a = _a , b = _b, c = _c, d = _d;
    }

    matrix operator *=(const matrix &x){
        unsigned long long tempA = (this->a * x.a + this->b * x.c) % MOD;
        unsigned long long tempB = (this->a * x.b + this->b * x.d) % MOD;
        unsigned long long tempC = (this->c * x.a + this->d * x.c) % MOD;
        unsigned long long tempD = (this->c * x.b + this->d * x.d) % MOD;
        this->a = tempA, this->b = tempB, this->c = tempC, this->d = tempD;
        return *this;
    }    
};

int main(){
    unsigned long long n;
    cin >> n;

    matrix fib(1, 1, 1, 0), rst;
    
    for(; n > 0; n = n >> 1){
        if(n&1){
            rst *= fib;
        }
        fib *= fib;
    }

    cout << rst.b << endl;

    return 0;
}

