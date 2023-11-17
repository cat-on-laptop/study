#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stack;

string connect = "CONNECT\n", disconnect = "DISCONNECT\n";
int parent[200'005];
bool visited[200'005];
int n, m;
vector<int> arr[200'005];
stack<int> op;
stack<string> rst;

int find(int x) {
	if (parent[x] < 0) return x; // parent[x]를 음수로 관리하면 개수가 cnt의 개수가 -parent[x]가 됨
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return;

	parent[px] += parent[py];
	parent[py] = px;
}

int main() {
	// freopen("input.in", "r", stdin);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;

	memset(parent, -1, sizeof(int) * (n + 1));

	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	
	for (int i = 0; i < n; ++i) {
		cin >> x; 
		op.push(x);
	}

	rst.push(disconnect); int size = 1, prev = 0;
	while (!op.empty()) {
		x = op.top(); op.pop(); 
		visited[x] = true;

		for (const int& e : arr[x]) // 현재 연결하는 node와 연결된 node들에 대하여 방문 했던(쿼리에 나왔던) 노드들만 연결
			if (visited[e])
				merge(e, x);
		
		
		rst.push(-parent[find(x)] == size ? connect : disconnect);
		++size;
	}

	while (!rst.empty()) {
		cout << rst.top();
		rst.pop();
	}
}