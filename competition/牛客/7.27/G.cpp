#include <bits/stdc++.h>
using namespace std;

struct LinearSieve {
    int n;
    vector<int> primes, minPrime, phi;
    explicit LinearSieve(int n) : n(n), minPrime(n + 1), phi(n + 1) {
        if (n >= 1) phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!minPrime[i]) { minPrime[i] = i; phi[i] = i - 1; primes.push_back(i); }
            for (int p : primes) {
                if (p > minPrime[i] || 1LL * i * p > n) break;
                minPrime[i * p] = p;
                if (i % p == 0) phi[i * p] = phi[i] * p;
                else phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    bool isPrime(int x) const { return x >= 2 && minPrime[x] == x; }
};

LinearSieve LS(1e7);

#define int long long

void solve() {
    int l, r, n;
    cin >> l >> r >> n;
    int tmp = n;
    vector <int> pri;
    while (tmp > 1) {
        int p = LS.minPrime[tmp];
        while (tmp % p == 0) tmp /= p;
        pri.push_back(p);
    }
    int mxp = 0;
    for (int i = n; i >= 1; i--) if (LS.isPrime(i)) {mxp = i; break;}
    auto calc1 = [&](int L, int R) -> int {
        if (L > R) return 0;
        int m = pri.size();
        int full = (1 << m) - 1;
        int ans = 0;
        for (int i = 0; i <= full; i++) {
            int cnt = 0, tot = 1;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    cnt++;
                    tot *= pri[j];
                }
            }
            if (cnt & 1) ans -= R / tot - (L - 1) / tot; 
            else ans += R / tot - (L - 1) / tot;
        }
        return 2LL * (R - L + 1) - ans;
    };
    auto calc2 = [&](int L, int R) -> int {
        if (L > R) return 0;
        vector <int> dp(n - L);
        for (int i = n - 1; i >= L; i--) {
            dp[i - L] = gcd(i, n);
            for (int j = i + 1; j < n; j++) {
                dp[i - L] = min(dp[i - L], dp[j - L] + gcd(i, j));
            }
        }
        int ans = 0;
        for (int i = L; i <= R; i++) ans += dp[i - L];
        return ans;
    };
    cout << calc1(l, min(mxp, r)) + calc2(max(l, mxp + 1), r) << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}