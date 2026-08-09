#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m > n) { cout << -1 << '\n'; return; }
    vector <int> cnt(m + 1);
    int tot = 0;
    auto add = [&](int x) {
        if (cnt[x] == 0) tot++;
        cnt[x]++;
    };
    auto del = [&](int x) {
        cnt[x]--;
        if (cnt[x] == 0) tot--;
    };
    int ans = n + 1;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        if (a[r] <= m) add(a[r]);
        while (tot == m && l <= r) {
            ans = min(ans, r - l + 1);
            if (a[l] <= m) del(a[l]);
            l++;
        }
    }
    if (ans == n + 1) cout << -1 << '\n';
    else cout << ans - m << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
