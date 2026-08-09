#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll qpow(ll a, ll b, ll p) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a % p) {
		if (b & 1) {
			ans = ans * a % p;
		}
	}
	return ans;
}


void solve() {
	int n, m;
	cin >> n >> m;
	ll val = 0;
	ll p = m * 10007;
	for (int i = 1; i <= n; i++) {
		int l, c;
		cin >> c >> l;
		val = val * qpow(10, l, p) % p + (qpow(10, l, 9 * p) - 1) / 9 * c % p;
		val %= p;
	}
	cout << val / m << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
//  n = q * m + r (r < m)
//  q = n / m
//  q = k * 10007 + ans (ans < 10007)
//  n = (k * 10007 + ans) * m + r
//  n = k * m * 10007 + m * ans + r
//  n % (m * 10007) = m * ans + r
//  ans = n % (m * 10007) / m

// A + "ccccc"(l个) = A * 10^l + c * (10 ^ l - 1) / 9
