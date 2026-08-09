#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector <bool> tag(n + 1);
	for (int i = 1, x; i <= k; i++) {
		cin >> x;
		tag[x] = 1;
	}
	vector <vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (k == 1) {
		cout << 0 << '\n';
		return;
	}
	int p1, p2, max_d = 0;
	function <void(int, int, int)> dfs1 = [&](int u, int f, int d) {
		if (tag[u] && max_d < d) {
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
	function <void(int, int, int)> dfs2 = [&](int u, int f, int d) {
		if (tag[u] && max_d < d) {
			max_d = d;
			p2 = u;
		}
		for (int v : g[u]) {	
			if (v == f) continue;
			dfs2(v, u, d + 1);
		}
	};
	dfs2(p1, 0, 0);
	cout << (max_d + 1) / 2 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}