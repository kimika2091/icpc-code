#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector<int>> g(n + 1), rg(n + 1);
    vector <int> vis(n + 1), exist(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vector <int> p(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> p[i];
    }
    exist[n] = exist[1] = 1;
    vis[n] = 1;
    auto dfs = [&](auto &self, int x) -> void {
        for (auto &y : rg[x]) {
            if (!exist[y] || vis[y]) continue;
            vis[y] = 1;
            self(self, y);
        }
    };
    dfs(dfs, n);
    int ans = -1;
    for (int k = q; k >= 0; k--) {
        if (vis[1]) {
            ans = k;
            break;
        }
        exist[p[k]] = 1;
        for (auto &v : g[p[k]]) {
            if (vis[v]) {
                vis[p[k]] = 1;
                dfs(dfs, p[k]);
                break;
            }
        }
    }
    if (ans == q) cout << "YES" << '\n';
    else if (ans == -1) cout << "NO" << '\n';
    else cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}