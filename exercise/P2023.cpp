#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Mint {
    int v;
    inline static int MOD = 1e9 + 7;
    static void set_mod(int m) { MOD = m; }

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
    vector<T> tree, add_tag, mul_tag;
    SegmentTree(int n) : n(n), tree(4 * n + 1, 0), add_tag(4 * n + 1, 0), mul_tag(4 * n + 1, 1) {}
    void push_up(int node) {
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    void push_down(int node, int l, int r) {
        if (mul_tag[node] != 1) {
            int mid = (l + r) / 2;
            add_tag[node * 2] *= mul_tag[node];
            mul_tag[node * 2] *= mul_tag[node];   
            tree[node * 2] *= mul_tag[node];
            add_tag[node * 2 + 1] *= mul_tag[node];
            mul_tag[node * 2 + 1] *= mul_tag[node];         
            tree[node * 2 + 1] *= mul_tag[node];
            mul_tag[node] = 1;
        }
        if (add_tag[node] != 0) {
            int mid = (l + r) / 2;
            add_tag[node * 2] += add_tag[node];
            tree[node * 2] += add_tag[node] * (mid - l + 1);
            add_tag[node * 2 + 1] += add_tag[node];
            tree[node * 2 + 1] += add_tag[node] * (r - mid);
            add_tag[node] = 0;
        }
    }
    void build(const vector<T> &a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        push_up(node);
    }
    void update_add(int node, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            add_tag[node] += val;
            tree[node] += val * (r - l + 1);
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update_add(node * 2, l, mid, ql, qr, val);
        if (qr > mid)
            update_add(node * 2 + 1, mid + 1, r, ql, qr, val);
        push_up(node);
    }
    void update_mul(int node, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            add_tag[node] *= val;
            mul_tag[node] *= val;
            tree[node] *= val;
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update_mul(node * 2, l, mid, ql, qr, val);
        if (qr > mid)
            update_mul(node * 2 + 1, mid + 1, r, ql, qr, val);
        push_up(node);
    }
    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];
        push_down(node, l, r);
        int mid = (l + r) / 2;
        T res = 0;
        if (ql <= mid)
            res += query(node * 2, l, mid, ql, qr);
        if (qr > mid)
            res += query(node * 2 + 1, mid + 1, r, ql, qr);
        return res;
    }
};

void solve() {
	int n, p;
	cin >> n >> p;
	Mint::MOD = p;
	vector<Mint> a(n + 1);
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	SegmentTree<Mint> tr(n + 1);
	tr.build(a, 1, 1, n);
	int m;
	cin >> m;
	for(int i = 1, o, t, g, c; i <= m; i++) {
		cin >> o >> t >> g;
		if (o == 1) {
			cin >> c;
			tr.update_mul(1, 1, n, t, g, c);
		}
		else if (o == 2) {
			cin >> c;
			tr.update_add(1, 1, n, t, g, c);
		}
		else {
			cout << tr.query(1, 1, n, t, g) << '\n';
		}
	}
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
