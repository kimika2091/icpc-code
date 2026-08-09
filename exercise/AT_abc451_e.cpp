#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
	int u, v, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

struct edge{
	int to, w;
};

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

void solve() {
	int n;
	cin >> n;
	vector <Edge> e;
	vector <vector<int>> a(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			int w;
			cin >> w;
			a[i][j] = a[j][i] = w;
			e.push_back({i, j, w});
		}
	}
	sort(e.begin(), e.end());
	DSU dsu(n);
	int cnt = 0;
	bool ok = 0;
	vector <vector<edge>> g(n + 1);
	for (auto &[u, v, w] : e) {
		if(dsu.same(u, v)) continue;
		dsu.merge(u, v);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		cnt ++;
		if (cnt == n - 1) {
			ok = 1;
			break;
		}
	}
	if (ok == 0) {
		cout << "No" << '\n';
		return;
	}

	vector <int> dis(n + 1, 0);
	function <void(int, int)> dfs = [&](int u, int f) -> void {
		for (auto &[v, w] : g[u]) {
			if (v != f) {
				dis[v] = dis[u] + w; 
				dfs(v, u);
			}
		}
	};

	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		dfs(i, 0);
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i][j] != dis[j]) {
				cout << "No" << '\n';
				return;
			}
		}
	}
	cout << "Yes" << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--){
		solve();
	}
	return 0; 
}
