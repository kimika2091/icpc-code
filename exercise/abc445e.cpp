#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7 + 5, MOD = 998244353;
int primes[MAXN], cnt, mpri[MAXN];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!mpri[i]) {
            primes[++cnt] = i;
			mpri[i] = i;
        }
        for (int j = 1; j <= cnt && 1ll * i * primes[j] <= n; j++) {
            mpri[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}
ll qpow (ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a % MOD) {
		if (b & 1) {
			ans = ans * a % MOD;
		}
	}
	return ans;
}

ll inv(ll x) {
	return qpow(x, MOD - 2);
}

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	map <int, int> mx1, mx2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ll x = a[i];
		while (x > 1) {
			int p = mpri[x], tot = 0;
			while (x % p == 0) x /= p, tot++;
			if (tot > mx1[p]) {
				mx2[p] = mx1[p];
				mx1[p] = tot;
			}
			else if (tot > mx2[p]) {
				mx2[p] = tot;
			}
		}
	}
	ll Lcm = 1;
	for (auto [p, tot] : mx1) Lcm = Lcm * qpow(p, tot) % MOD;
	for (int i = 1; i <= n; i++) {
		ll cur = Lcm;
		ll x = a[i];
		while (x > 1) {
			int p = mpri[x], tot = 0;
			while (x % p == 0) x /= p, tot++;
			if (mx1[p] == tot) {
				cur = cur * inv(qpow(p, mx1[p] - mx2[p])) % MOD;
			}
		}
		cout << cur << " \n"[i == n];
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	sieve(1e7);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
