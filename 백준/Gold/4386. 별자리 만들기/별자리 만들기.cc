#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::ios;
using std::sort;
using std::vector;
using std::pair;
using std::sqrt;

struct edge_t {
    int x, y;
	double weight;

    edge_t(int _x, int _y, double _weight) : x(_x), y(_y), weight(_weight) {}

    bool operator< (const edge_t& x) const {
        return this->weight < x.weight;
    }
};

int parent[100'005], rank[100'005];
int n;
vector<pair<double, double>> candidate;
vector<edge_t> arr;


int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = parent[x], py = parent[y];
    
    if(px == py) return;

    if(rank[px] < rank[py]) {
        parent[px] = py;
    }
    else if(rank[px] > rank[py]) {
        parent[py] = px;
    }
    else {
        parent[px] = py;
        ++rank[py];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
	for(int i = 0; i < n; ++i) parent[i] = i;

	double x, y;
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		candidate.emplace_back(x, y);
	}
    
    for(int i = 0; i < n; ++i) 
		for(int j = i + 1; j < n; ++j) 
			arr.emplace_back(i, j, sqrt((candidate[i].first - candidate[j].first)*(candidate[i].first - candidate[j].first)
			 + (candidate[i].second-candidate[j].second)*(candidate[i].second-candidate[j].second)));

	sort(arr.begin(), arr.end());

	int cnt = 0;
	double ans = 0;
	for(const edge_t &x : arr) {
		if(find(x.x) == find(x.y)) continue;

		merge(x.x, x.y);
		ans += x.weight;
	}

	cout << std::fixed;
	cout.precision(2);
	cout << ans;
}