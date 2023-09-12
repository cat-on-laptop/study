#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 3'005

using std::cin;
using std::cout;
using std::sort;
using std::vector;


struct info_t {
	int x, y, r;

	info_t(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {}

	bool operator<(const info_t& target) const {
		if (x * x + y * y == target.x * target.x + target.y * target.y) {
			if (x == target.x) {
				if (y == target.y) return r < target.r;
				return y < target.y;
			}
			return x < target.x;
		}
		return x * x + y * y < target.x * target.x + target.y * target.y;
	}
};

int n;
int parent[MAX];
int cnt[MAX];
vector<info_t> arr;

int find_1303(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find_1303(parent[x]);
}

void merge(int x, int y) {
	// x를 y의 아래로
	int px = find_1303(x), py = find_1303(y);

	if (px == py) return;
	
	parent[px] = py;
	cnt[py] += cnt[px];
	cnt[px] = 0;
}

void init() {
	arr.clear();
	for (int i = 0; i < MAX; ++i) parent[i] = i, cnt[i] = 1;
}

void input() {
	cin >> n;
	int x, y, r;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> r;
		arr.emplace_back(x, y, r);
	}
}

bool inRange(const info_t& x, const info_t& y) {
	return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) <= (x.r + y.r) * (x.r + y.r);
}

void process() {
	sort(arr.begin(), arr.end());
	
	for (int i = 1; i < n; ++i) 
		for(int j = i-1; j >= 0; --j)
			if (inRange(arr[j], arr[i])) merge(j,i);



	
	int tot = 0;
	for (int i = 0; i < n; ++i) if (cnt[i]) ++tot;
	cout << tot << '\n';

}

int main() {
	 // freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(0), cin.tie(0);
	
	int t; cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		init();
		input();
		process();
	}
}