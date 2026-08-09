#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

void solve() {
	int n, k, c;
	cin >> n >> k >> c;
	vector <vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <int> dis1(n + 1);
	int p1 = 1, p2 = 1, max_d = 0;
	function <void(int, int)> dfs1 = [&](int u, int f) {
		for (int v : g[u]) {
			if (v == f) continue;
			dis1[v] = dis1[u] + 1;
			if (dis1[v] > max_d) {
				max_d = dis1[v];
				p1 = v;
			}
			dfs1(v, u);
		}
	};
	dfs1(1, 0);
	vector <int> disp1(n + 1);
	max_d = 0;
	function <void(int, int)> dfs2 = [&](int u, int f) {
		for (int v : g[u]) {
			if (v == f) continue;
			disp1[v] = disp1[u] + 1;
			if (disp1[v] > max_d) {
				max_d = disp1[v];
				p2 = v;
			}
			dfs2(v, u);
		}
	};
	dfs2(p1, 0);
	vector <int> disp2(n + 1);
	function <void(int, int)> dfs3 = [&](int u, int f) {
		for (int v : g[u]) {
			if (v == f) continue;
			disp2[v] = disp2[u] + 1;
			dfs3(v, u);
		}
	};
	dfs3(p2, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, max(disp1[i], disp2[i]) * k - dis1[i] * c);
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