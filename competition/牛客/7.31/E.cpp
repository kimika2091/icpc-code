#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e7 + 5;
int primes[MAXN], cnt;
bool is_prime[MAXN];
int f[MAXN];

void sieve(int n) {
    fill(is_prime + 2, is_prime + n + 1, true);
    f[1] = 1;
    primes[0] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[++cnt] = i;
            f[i] = 1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            f[i * primes[j]] = f[i] + 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

const int MOD = 998244353;

int qpow (int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            c = c * a % MOD;
        }
    }
    return c;
}

void solve() {
    int N, c;
    cin >> N >> c;
    int ans = 0, base = c;
    for (int i = 1; i <= N; i++) {
        ans = (ans + primes[f[i] - 1] * base % MOD) % MOD;
        base = base * c % MOD;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    sieve(1e7);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0; 
}
