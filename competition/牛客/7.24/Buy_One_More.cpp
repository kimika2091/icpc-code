#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int qpow (int a, int b) {
    a %= MOD;
    int c = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            c = c * a % MOD;
        }
    }
    return c;
}

int inv (int x) { return qpow(x, MOD - 2); }

const int MAXN = 2e6 + 5;
int fac[MAXN], invFac[MAXN];

void precompute_combinations(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    invFac[n] = inv(fac[n]); 
    for (int i = n - 1; i >= 0; i--) invFac[i] = invFac[i + 1] * (i + 1) % MOD;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invFac[k] % MOD * invFac[n - k] % MOD;
}

void solve() {
    int n, m, c, a, b;
    cin >> n >> m >> c >> a >> b;
    if (m < n || (m - n) % c != 0) {
        cout << 0 << '\n';
        return;
    }
    int k = (m - n) / c;
    int p = a * inv(b) % MOD;
    int num = C(m, k) * n % MOD * inv(m) % MOD;
    cout << num * qpow(p, k) % MOD * qpow(1 - p + MOD, m - k) % MOD << '\n'; 
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    precompute_combinations(2e6);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
