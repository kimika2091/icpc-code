#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector <ll> a(n + 1), b;
    ll ans_l = 0, ans_r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < l) {
            ans_l += (l - a[i]);
            ans_r += (r - a[i]);
        } 
        else if (a[i] > r) {
            ans_l += (a[i] - l);
            ans_r += (a[i] - r);
        } 
        else {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    int m = b.size();
    vector<ll> pre(m + 1, 0);
    for (int i = 0; i < m; i++) pre[i + 1] = pre[i] + b[i];
    ll ans = 0;
    int j = m; 
    for (int i = 0; i <= m; i++) {
        auto check = [&](int j) -> ll {
            ll L = ans_l + i * l - pre[i] + (pre[m] - pre[j]) - 1ll * (m - j) * l;
            ll R = ans_r + i * r - pre[i] + (pre[m] - pre[j]) - 1ll * (m - j) * r;
            return min(L, R);
        };
        while (j > i) {
            if (check(j - 1) >= check(j)) j--;
            else break;
        }
        ans = max(ans, check(max(i, j)));
    }
    cout << max(0ll, ans) << "\n";
}   

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}