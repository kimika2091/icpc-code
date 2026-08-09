#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6;

vector <int> prime;
vector <bool> is_prime(N + 1, 1);
vector <int> mu(N + 1), f(N + 1), inv(N + 1), inv2(N + 1);
void preprocess() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int p : prime) {
            if (i * p > N) break;
            is_prime[i * p] = 0;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }
            else {
                mu[i * p] = -mu[i];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        int val = mu[i] * i % MOD * i % MOD;
        if (val < 0) val += MOD;
        for (int j = i; j <= N; j += i) {
            f[j] = (f[j] + val) % MOD;
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] %MOD;
    }
    for (int i = 1; i <= N; i++) {
        inv2[i] = inv[i] * inv[i] % MOD; 
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    vector <int> cnta(N + 1), cntb(N + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnta[a[i]] ++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        cntb[b[i]] ++;
    }
    vector <int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) {
        A[i] = i * cnta[i] % MOD;
        B[i] = i * cntb[i] % MOD;
    }
    vector <int> AA(N + 1), BB(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            AA[i] = (AA[i] + A[j]) % MOD;
            BB[i] = (BB[i] + B[j]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int t = AA[i] * BB[i] % MOD * f[i] % MOD * inv2[i] % MOD;
        ans = (ans + t) % MOD;
    }
    cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
    preprocess();
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}
// a * b / (gcd(a, b) ^ 2)