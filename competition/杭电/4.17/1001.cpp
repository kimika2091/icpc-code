#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll ans = 0;
    vector <ll> a(n + 1), cnt(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (s[i - 1] == '+') ? 1 : 0;
        cnt[i] = cnt[i - 1] + a[i];
        sum[i] = sum[i - 1] + a[i] * i;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll c = cnt[r] - cnt[l - 1], s = sum[r] - sum[l - 1];
        ll t = (s - (l - 1) * c) * 2 - c * c;
        ans ^= t;
    }
    cout << ans << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}