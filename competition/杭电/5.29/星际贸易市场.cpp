#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int inv2 = 499122177;

template <class T>
struct SegmentTree {
    int n;
    vector<T> sum, sum2, lazy;
    SegmentTree(int n) : n(n), sum(4 * n + 1, 0), sum2(4 * n + 1, 0), lazy(4 * n + 1, 0) {}
    void push_up(int node) {
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
		sum2[node] = sum2[node * 2] + sum2[node * 2 + 1];
		sum[node] %= MOD;
		sum[node] %= MOD;
    }
    void push_down(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            lazy[node * 2] += lazy[node];
			sum2[node * 2] += 2ll * lazy[node] * sum[node * 2] % MOD + (mid - l + 1) * lazy[node] % MOD * lazy[node] % MOD; 
            sum[node * 2] += lazy[node] * (mid - l + 1) % MOD;

            lazy[node * 2 + 1] += lazy[node];
            sum2[node * 2 + 1] += 2ll * lazy[node] * sum[node * 2 + 1] % MOD + (r - mid) * lazy[node] % MOD * lazy[node] % MOD; 
            sum[node * 2 + 1] += lazy[node] * (r - mid) % MOD;

            lazy[node] = 0;
			lazy[node * 2] %= MOD;
			lazy[node * 2 + 1] %= MOD;
			sum[node * 2] %= MOD;
			sum[node * 2 + 1] %= MOD;
			sum2[node * 2] %= MOD;
			sum2[node * 2 + 1] %= MOD;
        }
    }
    void build(const vector<T> &a, int node, int l, int r) {
        if (l == r) {
            sum[node] = a[l];
			sum2[node] = a[l] * a[l] % MOD;
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        push_up(node);
    }
    void update(int node, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            lazy[node] += val;
			sum2[node] += 2ll * val * sum[node] % MOD + (r - l + 1) * val % MOD * val % MOD;
            sum[node] += val * (r - l + 1) % MOD;

			lazy[node] %= MOD;
			sum[node] %= MOD;
			sum2[node] %= MOD;
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update(node * 2, l, mid, ql, qr, val);
        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        push_up(node);
    }
    T query_sum(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return sum[node];
        push_down(node, l, r);
        int mid = (l + r) / 2;
        T res = 0;
        if (ql <= mid){
			res += query_sum(node * 2, l, mid, ql, qr);
			res %= MOD;
		}
        if (qr > mid) {
            res += query_sum(node * 2 + 1, mid + 1, r, ql, qr);
			res %= MOD;
		}
        return res;
    }
	T query_sum2(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return sum2[node];
        push_down(node, l, r);
        int mid = (l + r) / 2;
        T res = 0;
        if (ql <= mid){
			res += query_sum2(node * 2, l, mid, ql, qr);
			res %= MOD;
		}
        if (qr > mid) {
            res += query_sum2(node * 2 + 1, mid + 1, r, ql, qr);
			res %= MOD;
		}
        return res;
    }
};

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
	return qpow(x, MOD - 2);
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector <int> a(n + 1);
	SegmentTree<int> tr(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	tr.build(a, 1, 1, n);
	while (q--) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1) {
			int d;
			cin >> d;
			tr.update(1, 1, n, l, r, d);
		}
		else {
			// cout << tr.query_sum(1, 1, n, l, r) << ' ' << tr.query_sum2(1, 1, n, l, r) << '\n';
			cout << inv2 * (tr.query_sum(1, 1, n, l, r) * tr.query_sum(1, 1, n, l, r) % MOD - tr.query_sum2(1, 1, n, l, r) + MOD) % MOD << '\n';
		}
	}
}



signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}