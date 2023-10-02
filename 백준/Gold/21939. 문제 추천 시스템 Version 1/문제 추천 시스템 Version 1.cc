#include <iostream>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::set;
using std::string;

struct info_t{
    int num, difficult;

    info_t(int n, int d) : num(n), difficult(d) {}

    bool operator<(const info_t& i) const {
        // 난이도 순
        if (difficult > i.difficult) return true;
        if (difficult < i.difficult) return false;

        // 번호 순
        if (num > i.num) return true;
        if (num < i.num) return false;

        return false;
    }
};

set<info_t> arr;
int diff[100'005];

void print() {
    for(auto iter = arr.begin(); iter != arr.end(); ++iter) 
        cout << "[" << iter->num << ", " << iter->difficult << "]\n";
    puts("");
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int p, l; cin >> p >> l;
        diff[p] = l;
        arr.emplace(p, l);
    }

    cin >> n;
    for(int i = 0; i < n; ++i) {
        string op; cin >> op;
        if (op == "add") {
            int p, l; cin >> p >> l;
            diff[p] = l;
            arr.emplace(p, l);
            // print();
        }
        else if (op == "solved") {
            int p; 
            cin >> p;
            arr.erase(arr.find({p, diff[p]}));
            // print();
        }
        else {
            int x; cin >> x;
            // print();
            if(x > 0) cout << arr.begin()->num << '\n';
            else cout << arr.rbegin()->num << '\n';
        }
    }

}