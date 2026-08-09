#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> val(n + 1);
	for (int i = 1; i <= n; i++) cin >> val[i];
	vector <int> a = val;
	sort(a.begin() + 1, a.end());
	a.erase(unique(a.begin() + 1, a.end()), a.end());
	for (int i = 1; i <= n; i++) {
		val[i] = lower_bound(a.begin() + 1, a.end(), val[i]) - a.begin();
	}
	vector <vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <bool> ans(n + 1, 0);
	vector <int> cnt(n + 1, 0);
	function <void(int, int)> dfs = [&](int u, int f) {
		ans[u] = ans[f] || cnt[val[u]];
		cnt[val[u]] ++;
		for (int v : g[u]) {
			if (v == f) continue;
			dfs(v, u);
		}
		cnt[val[u]] --;
	};
	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << (ans[i] ? "Yes" : "No") << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
