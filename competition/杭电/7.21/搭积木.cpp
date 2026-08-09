#include<bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    vector<int> parent, size;
    explicit DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x; size[x] += size[y];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int componentSize(int x) { return size[find(x)]; }
};

struct Node {
	int id;
	int a, b;
	double w() const { return 1.0 * b / a; }
	bool operator < (const Node &other) const {
		return w() > other.w();
	}
};

void solve() {
	int n;
	cin >> n;
	vector <Node> nodes(n + 1);
	for (int i = 1; i <= n; i++) nodes[i].id = i;
	for (int i = 1; i <= n; i++) cin >> nodes[i].a;
	for (int i = 1; i <= n; i++) cin >> nodes[i].b;
	vector <int> f(n + 1);
	vector <vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		if (f[i]) g[f[i]].push_back(i);
	}
	DSU dsu(n + 1);
	priority_queue <Node> q;
	for (int i = 1; i <= n; i++) {
		q.push(nodes[i]);
	}
	int ans = 0;
	vector <bool> vis(n + 1);
	while (!q.empty()) {
		auto [x, a, b] = q.top();
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		if (x == 1) continue;
		dsu.parent[x] = f[x];
		int ffx = dsu.find(f[x]);
		ans += nodes[x].a * nodes[ffx].b;
		nodes[ffx].a += nodes[x].a;
		nodes[ffx].b += nodes[x].b;
		q.push(nodes[ffx]);
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}