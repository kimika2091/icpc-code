#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

struct Edge {
    int to;
    int w;
};

struct Node {
    int id;
    ll dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void solve() {
	int t, n;
	cin >> t >> n;
	vector <vector<Edge>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	auto dijkstra = [&](int s, int t) -> void {
		vector <ll> dis(n + 1, inf);
		vector <bool> vis(n + 1, 0);
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		dis[s] = 0;
		pq.push({s, 0});
		while (!pq.empty()) {
			Node cur = pq.top();
			pq.pop();
			int u = cur.id;
			if (vis[u]) continue;
			vis[u] = true;
			for (auto &[v, w] : g[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					pq.push({v, dis[v]});
				}
			}
		}
		cout << dis[t] << '\n';
	};
	dijkstra(n, 1);
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
