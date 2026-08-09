#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int qpow (int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = a * a % MOD) {
		if (b & 1) {
			c = c * a % MOD;
		}
	}
	return c;
}
int inv (int x) {
	x %= MOD;
	return qpow(x, MOD - 2);
}

const int N = 1e7;
int fac[N + 5], inv_fac[N + 5];
void preprocess() {
	fac[0] = 1;
	for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % MOD;
	inv_fac[N] = inv(fac[N]);
	for (int i = N - 1; i >= 0; i--) inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}
int C(int n, int m) {
	return fac[n] * inv_fac[n - m] % MOD * inv_fac[m] % MOD;
}

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << inv(qpow(2, n - 1)) << '\n';
	}
	else {
		cout << (C(n, n / 2) + 2) * inv(qpow(2, n)) % MOD << '\n';
	}
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