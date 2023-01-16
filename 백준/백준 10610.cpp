// 백준 10610

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    // input
    cin >> s;
    
    sort(s.begin(), s.end(), greater<char>());
    // 큰 수가 앞에 오도록 정렬
    int tot = 0;
    for(const char &x : s) tot += x - '0';
    // 자릿 수의 합 구하기

    if(tot % 3 != 0 || *(s.end() - 1) != '0') cout << -1;
    // 30의 배수가 되려면 3의 배수이면서 10의 배수여야 함으로
    // 자릿수의 합이 3의 배수가 안되거나 끝자리가 0이 되지 않으면 -1
    else cout << s << endl;
    

    return 0;
}