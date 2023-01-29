// 백준 1629

#include <iostream>

typedef long long ll;

int main(void){
    ll a, b, c, temp, rst = 1;
    scanf("%lld %lld %lld", &a, &b, &c);

    temp = a % c;
    for(; b > 0; b = b >> 1){
        if(b & 1) rst = ((rst % c) * (temp % c)) % c;
        temp = ((temp % c) * (temp % c)) % c;
    }
    printf("%lld", rst);
}

// 백준 1629
// 거듭제곱을 빠르게 구하기

// #include <iostream>

// using namespace std;

// int main(){
//     long long a, b, c;
//     cin >> a >> b >> c;
//     long long rst = 1;
//     long long temp = a;
//     for(; b > 0; b = b >> 1){
//         cout << b << endl;
//         if(b & 1){
//             rst = ((rst % c) * (temp % c)) % c;
//         }
//         temp = ((temp % c) * (temp % c)) % c;
//     }

//     cout << rst;
// }