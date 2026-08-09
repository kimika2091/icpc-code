#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> e(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	auto bfs = [&](int x) {
		int cnt = 0;
		queue <int> q;
		vector<int> vis(n + 1);
		q.push(x);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(vis[u]) continue;
			vis[u] = ++cnt;
			for (int v : e[u]) {
				q.push(v);
			}
		}
		return cnt;
	};
	cout << bfs(1) ;
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
