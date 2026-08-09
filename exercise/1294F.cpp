#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int p1, p2, max_d = 0;
	function <void(int, int, int)> dfs1 = [&](int u, int f, int d) {
		if (max_d < d) {
			max_d = d;
			p1 = u;
		}
		for (int v : g[u]) {
			if (v == f) continue;
			dfs1(v, u, d + 1);
		}
	};
	dfs1(1, 0, 0);
	max_d = 0;
	vector <int> par(n + 1);
	function <void(int, int, int)> dfs2 = [&](int u, int f, int d) {
		par[u] = f;
		if (max_d < d) {
			max_d = d;
			p2 = u;
		}
		for (int v : g[u]) {
			if (v == f) continue;
			dfs2(v, u, d + 1);
		}
	};
	dfs2(p1, 0, 0);
	int p = p2;
	vector <int> path;
	vector <bool> is_d(n + 1);
	while (p != 0) {
		path.push_back(p);
		is_d[p] = 1;
		p = par[p];
	}
	int dist = 0, cur = 0;
	function <void(int, int, int)> dfs3 = [&](int u, int f, int d) {
		if (dist < d) {
			dist = d;
			cur = u;
		}
		for (int v : g[u]) {
			if (is_d[v] || v == f) continue;
			dfs3(v, u, d + 1);
		}
	};
	int ans = 0, p3 = 0;
	for (int i : path) {
		dist = 0;
		dfs3(i, 0, 0);
		if (ans < dist + max_d) {
			ans = dist + max_d;
			p3 = cur;
		}
	}
	if (p3 == 0) {
		p3 = par[p2];
	}
	cout << ans << '\n';
	cout << p1 << ' ' << p2 << ' ' << p3 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}