#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	map <int, vector<pair<int, int>>> mp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			mp[x].emplace_back(i, j);
		}
	}
	for (auto &[v, a] : mp) {
		map <int, vector<tuple<int, int, int>>> Rmn, Rmx;
		for (auto &[x, y] : a) {
			R[x].emplace_back();
		}
	}
	vector <vector<int>> d(n + 2, vector<int>(m + 2));
	auto diff = [&] (int r1, int c1, int r2, int c2, int v) -> void {
		d[r1][c1] += v;
		d[r1][c2 + 1] -= v;
		d[r2 + 1][c1] -= v;
		d[r2 + 1][c2 + 1] += v;
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}