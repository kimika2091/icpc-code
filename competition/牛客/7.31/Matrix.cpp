#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    bool ok = 1;
    if (n == 1) {
        for (int j = 1; j <= m; j++) if (a[1][j] != a[1][1]) ok = 0;
        cout << (ok ? 0 : -1) << '\n';
        return;
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++) if (a[i][1] != a[1][1]) ok = 0;
        cout << (ok ? 0 : -1) << '\n';
        return;
    }
    int ans = a[1][2] + a[2][1] - a[1][1] * 2;
    if (ans < 0) ok = 0;
    int B = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = B + ans - a[i][j];
            if (a[i][j] < 0 || a[i][j] > ans) ok = 0;
        }
    }
    if (a[1][1] != a[n][m]) ok = 0;
    if (ok == 0) {
        cout << -1 << '\n';
        return;
    }
    for (int d = 1; d <= n + m - 2; d++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int j = d + 1 - i;
            if (j >= 1 && j <= m) {
                sum += a[i][j];
            }
        }
        if (sum != ans) {
            ok = 0;
            break;
        }
    }
    if (ok == 0) {
        cout << -1 << '\n';
        return;
    }
    for (int d = 2; d <= n + m - 2; d++) {
        int s1 = 0, s0 = 0;
        for (int i = 1; i <= n; i++) {
            int j0 = d - i;
            int j1 = d + 1 - i;
            if (j1 >= 1 && j1 <= m) {
                s1 += a[i][j1];
                if (s1 < s0) ok = 0;
            }
            if (j0 >= 1 && j0 <= m) {
                s0 += a[i][j0];
                if (s0 < s1) ok = 0;
            }
            if (ok == 0) break;
        }
        if (ok == 0) break;
    }
    cout << (ok ? ans : -1) << '\n';
}   

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
