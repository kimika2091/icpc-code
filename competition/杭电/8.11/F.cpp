#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <bool> tag(n + 1);
    vector <vector<int>> L(n + 1);
    vector <int> mx1(n + 1), mx2(n + 2), mn(n + 2, 1e18);
    int mnr = 1e18;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        r--;
        tag[l] = 1;
        L[l].push_back(r);
        mnr = min(mnr, r);
    }
    for (int i = 1; i <= n; i++) {
        mx1[i] = mx1[i - 1];
        for (int &r : L[i]) {
            mx1[i] = max(mx1[i], r);A
        }
    }
    for (int i = n; i >= 1; i--) {
        mn[i] = mn[i + 1];
        mx2[i] = mx2[i + 1];
        if (tag[i]) mx2[i] = max(mx2[i], i);
        for (int &r : L[i]) {
            mn[i] = min(mn[i], r);
        }
    }
    bool ok = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= min(mnr, n - 2) && !ok; i++) {
        int low = max({i + 1, mx1[i] + 1, mx2[i + 1]});
        int high = min(n - 1, mn[i + 1]);
        if (low <= high) {
            ok = 1;
            x = i, y = low;
        }
    }
    if (!ok) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        cout << x + 1 << ' ' << y + 1 << '\n';
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
/*
1
6 4
1 2
2 5
3 6
4 1
*/
