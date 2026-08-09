#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
ll qpow(ll a, ll b) {
    ll c = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            c = c * a % MOD;
        }
    }
    return c;
}
ll inv(ll x) { return qpow(x, MOD - 2); }

void solve() {
    int n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector <ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] + b[i]) % MOD;
    }
    ll ans = 0, d = inv(sum), e = inv(2);
    for (int i = 1; i <= n; i++) {
        ans = (ans + a[i] * d % MOD * (pre[i - 1] + e * b[i] % MOD) %MOD) % MOD;
    }
    cout << ans << '\n';

}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
    cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
/*
5
1
1
1
2
1 1
1 1
3
1 0 2
0 2 1
3
2 1 0
0 1 2
4
1 2 1 0
0 1 1 2
*/