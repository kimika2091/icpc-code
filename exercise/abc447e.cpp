#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> fa, siz;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n + 1, 1);
    }
    int get(int x) {
        return fa[x] == x ? x : fa[x] = get(fa[x]);
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (siz[x] < siz[y])
            swap(x, y);
        fa[y] = x, siz[x] += siz[y];
        return 1;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

const int P = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <pair<int,int>> edges;
	DSU d(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}
	int cnt = n;
	for (int i = m - 1; i >= 0; i--) {
		if (cnt == 2) break;
		auto [u, v] = edges[i];
		if (d.same(u, v)) continue;
		d.merge(u, v);
		cnt--;
	}
	ll p = 1, ans = 0;
	for (auto [u, v] : edges) {
		p = p * 2 % P;
		if (d.same(u, v)) continue;
		ans = (ans + p) % P;
	}
	cout << ans << '\n';
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
