#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), f(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) sum += a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
    }
    if (sum != 0) {
        cout << (sum > 0 ? 1 : -1) << '\n';
        return;
    }
    vector <vector<int>> g(n + 1);
    vector <int> d(n + 1);
    for (int i = 2; i <= n; i++) {
        g[f[i]].push_back(i);
    }
    auto dfs = [&](auto &self, int x) -> void {
        for (int &y : g[x]) {
            d[y] = d[x] + (x != 1 && x < y); 
            self(self, y);
        }
    };
    dfs(dfs, 1);
    sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += a[i] * d[i];
    }
    if (sum == 0) cout << sum << '\n';
    else cout << (sum > 0 ? -1 : 1) << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}