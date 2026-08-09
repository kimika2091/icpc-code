#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

struct Edge {
    int to;
    int w;
};

void solve() {
	int n;
	cin >> n;
	vector <vector<Edge>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	ll maxd = 0, L, R;
	vector <int> par(n + 1);	
	function <void(int, int, int)> dfs1 = [&](int u, int f, ll d) -> void {
		if (maxd < d) {
			maxd = d;
			L = u;
		}
		for (auto &[v, w] : g[u]) {
			if (v == f) continue;
			dfs1(v, u, d + w);
		}	
	};
	dfs1(1, 0, 0);
	maxd = 0;
	function <void(int, int, int)> dfs2 = [&](int u, int f, int d) -> void {
		par[u] = f;
		if (maxd < d) {
			maxd = d;
			R = u;
		}
		for (auto &[v, w] : g[u]) {
			if (v == f) continue;
			dfs2(v, u, d + w);
		}
	};
	dfs2(L, 0, 0);
	cout << maxd << '\n';
	int p = R;
	vector <int> path;
	vector <bool> is_d(n + 1);
	while (p != 0) {
		path.push_back(p);
		is_d[p] = 1;
		p = par[p];
	}
	int dist = 0;
	function <void(int, int, int)> dfs = [&](int u, int f, int d) -> void {
		dist = max(dist, d);
		for (auto &[v, w] : g[u]) {
			if (v == f || is_d[v]) continue;
			dfs(v, u, d + w);
		}
	};
	int m = path.size();
	int U = 0, D = m - 1;
	vector <int> dis_R(m);
	for (int i = 1; i < m; i++) {
		for (auto &[v, w] : g[path[i]]) {
			if (v == path[i - 1]) {
				assert(w != 0);
				dis_R[i] = dis_R[i - 1] + w;
				break;
			}
		}
	}
	for (int i = 1; i < m; i++) {
		dist = 0;
		dfs(path[i], 0, 0);
		if (dist == dis_R[i]) U = i;
		else break;
	}
	for (int i = m - 1; i >= 0; i--) {
		dist = 0;
		dfs(path[i], 0, 0);
		if (dist == (maxd - dis_R[i])) D = i;
		else break;
	}
	cout << D - U << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
