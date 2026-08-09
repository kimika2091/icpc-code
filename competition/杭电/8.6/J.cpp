#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
        cout << 0 << '\n';
        return;
    }
    int z = 0;
    if (x >= 2) z = x - 2 - (x - 2) / (y + 1);
    int q = z / y, r = z % y;
    int ans = x * y + y * (y - 1) / 2 + z * (x - 1) - (z * z + (y - r) * q * q + r * (q + 1) * (q + 1)) / 2;
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}