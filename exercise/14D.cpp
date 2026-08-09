#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int calc(const vector<vector<int>> &g, int s, int p) {
	vector <int> dp(n + 1);
	int ans = 0;
	function <void(int, int)> dfs = [&](int u, int f) {
		for (int v : g[u]) {
			if (v == f || v == p) continue;
			dfs(v, u);
			ans = max(ans, dp[u] + dp[v] + 1);
			dp[u] = max(dp[u], dp[v] + 1);
		}
	};
	dfs(s, 0);
	return ans;
}

void solve() {
	cin >> n;
	vector <vector<int>> g(n + 1);
	vector <pair<int, int>> e;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		e.push_back({u, v});
	}
	ll ans = 0;
	for (auto &[u, v] : e) {
		ans = max(ans, 1ll * calc(g, u, v) * calc(g, v, u));
	}
	cout << ans << '\n';
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