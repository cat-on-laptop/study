#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> g[10005];
bool visited[10005];
int level[10005];
int v, e, v1, v2;
int parent[17][10005]; // prant[k][x] := x의 x^k번째 부모

void init() {
}

int lca(int x, int y) {
	// x가 더 깊음
	if (level[x] < level[y]) swap(x, y);

    
    // level 맞추기
	for (int r = 16; r >= 0; --r) {
    	if (level[x] - level[y] >= (1 << r)) {
        	x = parent[r][x];
        }
    }

	if (x == y) return x;

	for (int i = 16; i >= 0; --i) {
		if (parent[i][x] != parent[i][y]) {
			x = parent[i][x], y = parent[i][y];
		}
	}
	return parent[0][x];
}



void dfs(int curr = 1) {
	for (const int &x : g[curr]) {
		if (!visited[x]) {
			visited[x] = true;
			level[x] = level[curr] + 1;
			dfs(x);
		}
	}
}

void preprocessing() {
	// sparse table 구성
	for (int k = 1; k < 17; ++k) {
		for (int node = 1; node <= v; ++node) {
			parent[k][node] = parent[k - 1][parent[k - 1][node]];
			// parent[r][i] 는 parent[r-1][i]의 2^(r-1) 부모
		}
	}
	dfs();
}

int dfs2(int curr) {
	int cnt = 1;
	for (const int &x : g[curr]) {
		if (!visited[x]) {
			visited[x] = true;
			cnt += dfs2(x);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio, cin.tie(0);
	int t; cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
        // init
        for (int i = 0; i < 10005; ++i) g[i] = {};
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        memset(level, 0, sizeof(level));


        // input
        cin >> v >> e >> v1 >> v2;
        int p, c;
        for (int i = 0; i < e; ++i) {
            cin >> p >> c;
            g[p].push_back(c);
            parent[0][c] = p;
        }
		
		preprocessing();
    
		int a = lca(v1, v2);
		memset(visited, false, sizeof(visited));
		int s = dfs2(a);

		cout << "#" << tc << " " << a << ' ' << s << endl;
	}
	return 0;
}