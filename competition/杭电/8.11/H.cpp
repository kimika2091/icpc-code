#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, w;
    cin >> n >> w;
    string op;
    cin >> op;
    vector <int> a(n);
    a[0] = w;
    for (int i = 0; i < n - 1; i++) {
       if (op[i] == '&') a[i + 1] = (1 << 31) - 1;
       else a[i + 1] = 0;
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}