#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> a(n + 1), s(n + 1);
    queue <int> q;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        a[x] = 1;
        s[x] = 1;
        q.push(x);
    }
    vector <int> cnt(n + 1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int &y : g[x]) {
            if (a[y] == 1) continue;
            cnt[y]++;
            if (cnt[y] == 2) {
                a[y] = 1;
                q.push(y);
            } 
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 0) {
            bool ok = 0;
            for (int &j : g[i]) {
                if (a[j]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int &x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}