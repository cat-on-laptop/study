#include <iostream>

using std::cin;
using std::cout;

struct node_t{
    int left, right;
}arr[26];

void preorder(int curr) {
    cout << char(curr + 65);
    if(arr[curr].left > 0) preorder(arr[curr].left);
    if(arr[curr].right > 0) preorder(arr[curr].right);
}

void postorder(int curr) {
    if(arr[curr].left > 0) postorder(arr[curr].left);
    if(arr[curr].right > 0) postorder(arr[curr].right);
    cout << char(curr + 65);
}

void inorder(int curr) {
    if(arr[curr].left > 0) inorder(arr[curr].left);
    cout << char(curr + 65);
    if(arr[curr].right > 0) inorder(arr[curr].right);
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        char a,b,c;
        cin >> a >> b >> c;
        arr[a-65].left = b != '.' ? b-'A' : -1;
        arr[a-65].right = c != '.' ? c-'A' : -1;
    }

    preorder(0); puts("");
    inorder(0); puts("");
    postorder(0); puts("");
    return 0;
}