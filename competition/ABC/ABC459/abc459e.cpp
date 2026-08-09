#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<int MOD>
struct Mint {
    int v;
    Mint(long long _v = 0) {
        if (_v < 0) v = (_v % MOD + MOD) % MOD;
        else v = _v % MOD;
    }

    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = 1LL * v * o.v % MOD; return *this; }
    
    friend Mint qpow(Mint a, long long p) {
        Mint res = 1;
        for (; p; p >>= 1, a *= a) if (p & 1) res *= a;
        return res;
    }
    
    Mint inv() const { return qpow(*this, MOD - 2); }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    
    bool operator==(const Mint& o) const { return v == o.v; }
    bool operator!=(const Mint& o) const { return v != o.v; }
    friend ostream& operator<<(ostream& os, const Mint& a) { return os << a.v; }
    friend istream& operator>>(istream& is, Mint& a) { long long t; is >> t; a = Mint(t); return is; }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

const int MAXN = 1e6 + 5;
mint fac[MAXN], invFac[MAXN];

void precompute_combinations(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    invFac[n] = fac[n].inv(); 
    for (int i = n - 1; i >= 0; i--) invFac[i] = invFac[i + 1] * (i + 1);
}

mint C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
	if (k == 0) return 1;
	mint res = 1;
	for (int i = 0; i < k; i++) {
		res = res * (n - i);
	}
    return res * invFac[k];
}

void solve() {
	int n;
	cin >> n;
	vector <vector<int>> g(n + 1);
	vector <ll> c(n + 1), d(n + 1);
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> d[i];
	vector <mint> dp(n + 1);
	vector <ll> sum_c(n + 1), sum_d(n + 1);
	function <void(int)> dfs = [&](int u) -> void {
		sum_c[u] = c[u];
		sum_d[u] = d[u];
		dp[u] = 1;
		for (int v : g[u]) {
			dfs(v);
			sum_c[u] += sum_c[v];
			sum_d[u] += sum_d[v];
			dp[u] = dp[u] * dp[v];
		}
		if (dp[u] == 0) return;
		if (sum_c[u] < sum_d[u]) {
			dp[u] = 0;
			return;
		}
		dp[u] = dp[u] * C(sum_c[u] - (sum_d[u] - d[u]), d[u]);
	};
	dfs(1);
	cout << dp[1] << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	precompute_combinations(1e6 + 1);
	while(T--) {
	    solve();
	}
	return 0; 
}