#include<bits/stdc++.h>
using namespace std;
#define int long long

template<int MOD>
struct Mint {
    int v;
    Mint(int _v = 0) {
        if (_v < 0) v = (_v % MOD + MOD) % MOD;
        else v = _v % MOD;
    }

    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = v * o.v % MOD; return *this; }
    
    friend Mint qpow(Mint a, int p) {
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
    friend istream& operator>>(istream& is, Mint& a) { int t; is >> t; a = Mint(t); return is; }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

template <class T>
struct Matrix {
    int r, c;
    vector<vector<T>> mat;
    Matrix(int r, int c, T v = 0) : r(r), c(c), mat(r, vector<T>(c, v)) {}
    static Matrix eye(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) res.mat[i][i] = 1;
        return res;
    }
    Matrix operator*(const Matrix& o) const {
        Matrix res(r, o.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < o.c; j++) {
                    res.mat[i][j] += mat[i][k] * o.mat[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator^(int p) const {
        Matrix res = eye(r);
        Matrix a = *this;
        while (p > 0) {
            if (p & 1) res = res * a;
            a = a * a;
            p >>= 1;
        }
        return res;
    }
    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << mat[i][j] << (j == c - 1 ? "" : " ");
            cout << '\n';
        }
    }
};

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = a * a % MOD) {
		if (b & 1) {
			c = c * a % MOD;
		}
	}
	return c;
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 3LL * qpow(2, m - 1) % MOD << '\n';
		return;
	}
	auto to = [&](int x0, int x1, int cur) -> vector<int> {
		vector <int> x(n);
		x[0] = x0, x[1] = x1;
		for (int i = 2; i < n; i++) {
			if (cur & 1) x[i] = x[i - 2];
			else x[i] = 3 - x[i - 1] - x[i - 2];
			cur >>= 1;
		}
		return x;
	};
	auto check = [&](const vector <int> &a, const vector <int> &b) -> int {
		for (int i = 2; i < n; i++) {
			if (a[i] == b[i]) return 0;
		}
		return 1;
	};
	int N = 1 << (n - 2);
	Matrix<mint> T(N, N);
    
    for (int b0 = 0; b0 < 3; b0++) for (int b1 = 0; b1 < 3; b1++) {
        if (b0 == b1 || b0 == 0 || b1 == 1) continue;
        for (int i = 0; i < N; i++) {
            vector <int> a = to(0, 1, i);
            for (int j = 0; j < N; j++) {
                vector <int> b = to(b0, b1, j);
                T.mat[i][j] = T.mat[i][j] + check(a, b);
            }
        }		
    }
    
	Matrix<mint> dp(1, N, 6);
	dp = dp * (T ^ (m - 1));
	mint ans = 0;
	for (int i = 0; i < N; i++) {
		ans = ans + dp.mat[0][i];
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}