#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    ll n;
    cin >> n;
    
    auto count = [&](ll x) -> ll {
        if (x == 0) return n * (n - 1) / 2; 
        return (n / x) * (n + 1) - x * ((n / x) * (n / x + 1)) / 2;
    };
    
    ll m = __lg(n), ans = 0;
    for (int i = 0; i <= m; i++) {
        ll L = 1 << i, R = min(L * 2 - 1, n);
        ans += (count(L) - count(R + 1)) * i;
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