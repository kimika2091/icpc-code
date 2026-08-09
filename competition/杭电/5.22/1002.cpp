#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    int d1 = 0, d2 = 0, d3 = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a && b) c3++, d3 += c;
        if (a) c1++, d1 += c;
        if (b) c2++, d2 += c; 
    }
    
    cout << fixed << setprecision(2) << max({1.0 * d1 / c1, 1.0 * d2 / c2, 1.0 * d3 / c3}) * 100 << '%' << '\n';

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