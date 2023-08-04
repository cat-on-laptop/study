#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100005

using namespace std;

vector<int> u[MAX], d[MAX];
int n, m, target, cnt;
bool visited[MAX];

void up(int curr) {
	visited[curr] = true;
	++cnt;

	for (const int& x : u[curr]) 
		if (!visited[x]) 
			up(x);
		
}

void down(int curr) {
	visited[curr] = true;
	++cnt;
	//printf("curr : %d, cnt : %d\n", curr, cnt);
	for (const int& x : d[curr])
		if (!visited[x])
			down(x);
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> target;

	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		u[y].push_back(x);
		d[x].push_back(y);
	}

	up(target); 
	int x = cnt; // x -> target 포함 target의 위에 있는 사람의 수

	memset(visited, false, sizeof(visited));
	cnt = 0;
	down(target);
	int y = cnt; // y -> target 포함 target 아래에 있는 사람의 수
	--y;

	cout << x << endl << n - y;
}