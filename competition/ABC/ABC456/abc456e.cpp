#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cycle_detection(const vector<vector<int>> &g, vector<int> &deg) {
    int n = g.size();
	queue <int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	int cnt = 0;
	while (!q.empty()) {
		int u = q.front();
		cnt ++;
		q.pop();
		for (int v : g[u]) {
			deg[v] --;
			if (deg[v] == 0) q.push(v);
		}
	}
	return cnt != n;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector <pair<int,int>> edges;
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		edges.push_back({v, u});
	}
	int w;
	cin >> w;
	vector <string> s(n + 1);
	auto id = [&](int x, int y) -> int {
		return x * w + y;
	};
	for (int i = 1; i <= n; i++) cin >> s[i];
	vector <vector<int>> g((n + 1) * w + 1);
	vector <int> deg((n + 1) * w + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < w; j++) {
			if (s[i][j - 1] == 'o' && s[i][j] == 'o') {
				g[id(i, j)].push_back(id(i, j + 1));
				deg[id(i, j + 1)] ++;
			}
		}
		if (s[i][w - 1] == 'o' && s[i][0] == 'o') {
			g[id(i, w)].push_back(id(i, 1));
			deg[id(i, 1)] ++;
		}
	}
	for (auto [u, v] : edges) {
		for (int i = 1; i < w; i++) {
			if (s[u][i - 1] == 'o' && s[v][i] == 'o') {
				g[id(u, i)].push_back(id(v, i + 1));
				deg[id(v, i + 1)] ++;
			}
		}
		if (s[u][w - 1] == 'o' && s[v][0] == 'o') {
			g[id(u, w)].push_back(id(v, 1));
			deg[id(v, 1)] ++;
		}
	}
	cout << (cycle_detection(g, deg) ? "Yes" : "No") << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
