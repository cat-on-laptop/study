// 메인 아이디어 := 분리가 아닌 합치는 걸로 생각해보면 분해의 역순으로 연결했다 생각해보면 됨
// 쿼리에 등장하지 않는 결합은 이미 결합된 상태로 가정 후 풀이

#include <iostream>
#include <stack>

#define MAX 100005

using std::cin;
using std::cout;
using std::stack;

struct query_t {
	int x, y;

	query_t(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};


int n, m, q;
int parent[MAX], cnt[MAX];
bool visited[MAX];
query_t DAT[MAX];
stack<int> st;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

long long merge(int x, int y) {
	int px = find(x), py = find(y);

	if (px == py) return 0;

	parent[py] = px;
	long long rst = (long long) (cnt[px]) * cnt[py];
	cnt[px] += cnt[py];
	cnt[py] = 0;

	return rst;
}

void input() {
	cin >> n >> m >> q;
	int x, y;

	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		DAT[i] = query_t(x, y);
	}


	for (int i = 0; i < q; ++i) {
		cin >> x; --x;
		visited[x] = true;
		st.emplace(x);
	}


}


void process() {
	for (int i = 1; i <= n; ++i) parent[i] = i, cnt[i] = 1;

	int x, y;

	// 제거 안하는 간선은 연결
	for (int i = 0; i < m; ++i) {
		if (visited[i]) continue;
		x = DAT[i].x, y = DAT[i].y;
		merge(x, y);
	}

	long long ans = 0;

	while (!st.empty()) {
		int curr = st.top(); st.pop();

		ans += merge(DAT[curr].x, DAT[curr].y);
	}

	cout << ans;
	
}

int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);

	input();
	process();
	
}