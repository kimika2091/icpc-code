#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int N = 2e6;
vector <int> inv(N + 1);

int qpow(int a, int b) {
    int c = 1;
    a %= MOD;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            c = c * a % MOD;
        }
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    vector <int> suf_a(n + 1), suf_b(n + 1);
    for (int i = n - 1; i >= 1; i--) {
        int r = min(i * 2, n - 1);
        a[i] = (1 - suf_a[r + 1] + MOD) % MOD;
        a[i] = a[i] * inv[i * 2] % MOD;
        b[i] = suf_b[r + 1] * inv[i * 2] % MOD;
        b[i] = (1 - b[i] + MOD) % MOD;
        suf_a[i] = (a[i] + suf_a[i + 1]) % MOD;
        suf_b[i] = (b[i] + suf_b[i + 1]) % MOD;
    }
    int t = suf_b[1] * qpow(1 - suf_a[1] + MOD, MOD - 2) % MOD;
    cout << (a[1] * t % MOD + b[1]) % MOD << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
