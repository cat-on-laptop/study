#include <iostream>
#include <string>
#include <bitset>
#define endl '\n'
using namespace std;

inline int mymax(int x, int y){
    return x > y ? x : y;
}

int selected;
int n, k, ans;
int word[50];

void backtrack(int start, int learn){
    int cnt = 0;
    if(learn == k){
        for(int i = 0; i < n; ++i){
            if((word[i] & selected) == word[i]) ++cnt;
        }
        
        ans = mymax(ans, cnt);
        return;
    }

    for(int i = start; i < 26; ++i){
        if(!(selected & (1 << i))){
            selected |= (1 << i);
            backtrack(i + 1, learn + 1);
            selected &= ~(1 << i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    if(k < 5){
        cout << 0 << endl;
        return 0;
    }
    else if(k == 26){
        cout << n << endl;
        return 0;
    }

    string str;
    selected |= 1 << ('a' - 'a');
    selected |= 1 << ('n' - 'a');
    selected |= 1 << ('t' - 'a');
    selected |= 1 << ('i' - 'a');
    selected |= 1 << ('c' - 'a');


    for(int i = 0; i < n; ++i){
        cin >> str;
        word[i] = selected;
        for(int j = 4; j < str.length() - 4; ++j){
            word[i] |= (1 << (str[j] - 'a'));
        }
    }

    // for(int i = 0; i < n; ++i){
    //     cout << bitset<26> (word[i]) << endl;
    // }
    backtrack(0, 5);
    cout << ans << endl;
    return 0;
}