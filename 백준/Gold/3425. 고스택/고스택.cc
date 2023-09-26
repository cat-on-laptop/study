#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define threshold 1000000000
#define MAX 1005

using namespace std;

typedef long long ll;
vector<string> order;
vector<int> number;
ll stack[MAX];
int top;

int main(){
    // freopen("input.txt", "r" , stdin);
    string op;
    int temp, numIdx, first_num, N;
    bool err;
    while(true){
        // init
        order = {}, number = {};
        while(true){
            // input
            cin >> op;
            if(op == "NUM"){
                cin >> temp;
                number.push_back(temp);
            }
            else if(op == "END") break;
            else if(op == "QUIT") return 0;
            order.push_back(op);
        }
        cin >> N;
        for(int i = 0; i < N; ++i){
            numIdx = 0, top = -1, err = false;
            cin >> stack[++top];
            for(int i = 0; i < order.size(); ++i){
                if(order[i] == "NUM"){
                    stack[++top] = number[numIdx++];
                }
                else if(order[i] == "POP"){
                    if(top < 0){
                        err = true;
                        break;
                    }
                    --top;
                }
                else if(order[i] == "INV"){
                    if(top < 0){
                        err = true;
                        break;
                    }
                    stack[top] *= -1;
                }
                else if(order[i] == "DUP"){
                    if(top < 0){
                        err = true;
                        break;
                    }
                    stack[++top] = stack[top];
                }
                else if(order[i] == "SWP"){
                    if(top < 1){
                        err = true;
                        break;
                    }
                    swap(stack[top-1], stack[top]);
                }
                else if(order[i] == "ADD"){
                    if(top < 1){
                        err = true;
                        break;
                    }
                    stack[top - 1] += stack[top]; --top;
                }
                else if(order[i] == "SUB"){
                    if(top < 1) {
                        err = true;
                        break;
                    }
                    stack[top - 1] -= stack[top]; --top;
                }
                else if(order[i] == "MUL"){
                    if(top < 1){
                        err = true;
                        break;
                    }
                    stack[top - 1] *= stack[top]; --top;
                }
                else if(order[i] == "DIV"){
                    if(top < 1){
                        err = true;
                        break;
                    }
                    if(stack[top] == 0){
                        err = true;
                        break;
                    }
                    bool first = stack[top] < 0, second = stack[top-1] < 0;
                    stack[top - 1] = abs(stack[top - 1]) / abs(stack[top]);
                    if(first ^ second) stack[top-1] *= -1;
                    --top;
                }
                else if(order[i] == "MOD"){
                    if(top < 1){
                        err = true;
                        break;
                    }
                    if(stack[top] == 0){
                        err = true;
                        break;
                    }
                    bool minus = stack[top - 1] < 0;
                    stack[top - 1] = abs(stack[top - 1]) % abs(stack[top]);
                    if(minus) stack[top - 1] *= -1;
                    --top;
                }
            }
            if(top != 0) err = true;
            if(abs(stack[top]) > threshold) err = true;
            if(err) cout << "ERROR\n";
            else cout << stack[top] << '\n';
        }
        cout << '\n';
    }
}
