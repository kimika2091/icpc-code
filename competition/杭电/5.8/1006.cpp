#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector<pair<int,int>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector <bool> is_save(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        is_save[x] = 1;
    }
    ll ans = 0;
    function <int(int, int)> dfs = [&](int u, int f) -> int {
        int cnt = 0;
        bool leaf = 1;
        for (auto &[v, w] : g[u]) {
            if (v == f) continue;
            leaf = 0;
            int cnt1 = dfs(v, u);
            cnt += cnt1;
            if (!is_save[v]) {
                ans += w * (cnt1 - 1);
            }
        }
        if (leaf) return 1;
        return cnt;
    };
    dfs(1, 0);
    cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
    cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
/*
5
1 1
1

3 1
1 2 5
2 3 7
1

5 1
1 2 3
1 3 4
3 4 6
3 5 8
1

5 2
1 2 3
1 3 4
3 4 6
3 5 8
1 3
7 2
1 2 2
2 3 5
2 4 7
1 5 3
5 6 11
5 7 13
1 2
*/