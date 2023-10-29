/*
	union - find 유형 두 번째
	그래프 분리 -> 거꾸로 생각하면 그래프 합치기임
*/

#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::stack;
using std::string;

const string yes = "YES\n", no = "NO\n";

int parent[200'005], DAT[200'005];

struct OP {
	int op, x, y;
};

stack<OP> st;
stack<string> rst;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;

	parent[px] = py;
	return;
}

int n, q;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 2; i <= n; ++i) 
		cin >> DAT[i];
	
	int op, x, y;
	for (int i = 0; i < q + n - 1; ++i) {
		cin >> op;
		if (op) {
			cin >> x >> y;
			st.push({ op, x, y });
		}
		else {
			cin >> x;
			st.push({ op,x });
		}
	}

	while (!st.empty()) {
		OP curr = st.top(); st.pop();
		if (curr.op) {
			if (find(curr.x) == find(curr.y))
				rst.push(yes);
			else
				rst.push(no);
		}
		else {
			merge(curr.x, DAT[curr.x]);
		}
	}

	while (!rst.empty()) {
		cout << rst.top();
		rst.pop();
	}

	return 0;
}