#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Mint {
    int v;
	static inline int MOD = 1;
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

template <class T>
struct SegmentTree {
    int n;
    vector<T> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 1, 0) {}
    void push_up(int node) {
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        push_up(node);
    }
    void update(int node, int l, int r, int x, T val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
            update(node * 2, l, mid, x, val);
        if (x > mid)
            update(node * 2 + 1, mid + 1, r, x, val);
        push_up(node);
    }
    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        T res = 1;
        if (ql <= mid)
            res *= query(node * 2, l, mid, ql, qr);
        if (qr > mid)
            res *= query(node * 2 + 1, mid + 1, r, ql, qr);
        return res;
    }
};

void solve() {
	int Q, M;
	cin >> Q >> M;
	Mint::MOD = M;
	SegmentTree<Mint> tr(Q);
	tr.build(1, 1, Q);
	for (int i = 1, op, x; i <= Q; i++) {
		cin >> op >> x;
		if (op == 1) {
			tr.update(1, 1, Q, i, x);
		}
		else {
			tr.update(1, 1, Q, x, 1);
		}
		cout << tr.tree[1] << '\n';
	}

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
