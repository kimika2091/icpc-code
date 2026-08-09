#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int inv2 = 499122177, inv6 = 166374059;

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
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	vector <int> sum(n + 1);
	function <void(int, int)> dfs = [&](int u, int f) -> void {
		sum[u] = a[u];
		int c1 = 0, c2 = 0, c3 = 0;
		for (int v : g[u]) {
			if (v == f) continue;
			dfs(v, u);
			sum[u] += sum[v];
			c2 += sum[v] * sum[v] % MOD;
			c3 += sum[v] * sum[v] % MOD * sum[v] % MOD;
			sum[u] %= MOD;
			c2 %= MOD;
			c3 %= MOD;
		}
		c1 = (sum[u] - a[u] + MOD) % MOD;
		ans += inv2 * a[u] % MOD * (c1 * c1 % MOD - c2 + MOD) % MOD;
		ans %= MOD;
		ans += inv6 * (c1 * c1 % MOD * c1 % MOD - 3ll * c1 * c2 % MOD + 2ll * c3 % MOD + MOD) % MOD;
		ans %= MOD;
	};
	dfs(1, 0);
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