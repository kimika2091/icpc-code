#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int base[32];
void insert(int x) {
    for (int i = 31; i >= 0; i--) {
        if (!(x >> i)) continue;
        if (!base[i]) {
            base[i] = x;
            return;
        }
        x ^= base[i];
    }
}

int query(int x) {
    for (int i = 31; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (base[i]) x ^= base[i];
        }
    }
    return x;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 1 ^ n;
    for (int i = 0; i <= 31; i++) base[i] = 0;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        insert(u ^ v ^ w);
    }
    cout << query(ans) << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
