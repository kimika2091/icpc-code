#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int m, a, b;
	cin >> m >> a >> b;
	vector <vector<int>> g(m * m);
	auto id = [&](int x, int y) -> int {
		return x * m + y;
	};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int k = (a * i + b * j) % m ;
 			g[id(k, i)].push_back(id(i, j));
		}
	}
	queue <int> q;
	vector <bool> vis(m * m, 0);
	for (int i = 0; i < m; i++) {
		q.push(id(0, i));
		if (i) q.push(id(i, 0));
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : g[u]) {
			q.push(v);
		}
	}
	int ans = 0;
	for (int i = 0; i < m * m; i++) {
		ans += (vis[i] == 0);
	}
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
