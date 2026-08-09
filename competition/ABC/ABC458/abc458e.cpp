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

const int MAXN = 2e6 + 5;
mint fac[MAXN], invFac[MAXN];

void precompute_combinations(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    invFac[n] = fac[n].inv(); 
    for (int i = n - 1; i >= 0; i--) invFac[i] = invFac[i + 1] * (i + 1);
}

mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invFac[k] * invFac[n - k];
}

void solve() {
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;
	mint ans(0);
	for (int i = 1; i <= x2 + 1; i++) {
		ans += C(x2 + 1, i) * C(x1 - 1, i - 1) * C(x2 - i + x3, x3);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	precompute_combinations(2e6);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}

// C(x2 + 1, i) * C(x1 - 1, i - 1) * C(x2 + x3 - i, x3)