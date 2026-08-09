#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int pre = -1E9;

    bool ok = true;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x > pre) {
                if (v == -1) {
                    v = x;
                }
                else {
                    v = min(v, x);
                }
            }
        }

        if (v == -1) {
            ok = false;
        }

        pre = v;
    }

    if (ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}