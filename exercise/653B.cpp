#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector <vector<string>> d(6);
	for (int i = 1; i <= q; i++) {
		string a, b;
		cin >> a >> b;
		d[b[0] - 'a'].push_back(a);
	}
	int ans = 0;
	map <string, int> vis;
	function <void(string)> dfs = [&](string s) -> void {
		if (vis[s] == 1) return;
		vis[s] = 1;
		if (s.size() == n) {
			ans++;
			return;
		}
		for (auto t : d[s[0] - 'a']) {
			dfs(t + s.substr(1));
		}
	};
	dfs("a");
	cout << ans;
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
