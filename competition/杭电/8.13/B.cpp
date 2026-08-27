#include <bits/stdc++.h>
using namespace std;

using ULL = uint64_t;

struct SegmentTree {
    vector <ULL> sum, lazy;
    SegmentTree(int n) : sum(n * 4 + 1), lazy(n * 4 + 1) {};
    void pushup (int o) {
        sum[o] = sum[o << 1] + sum[o << 1 | 1];
    }
    void addtag (int o, int l, int r, ULL v) {
        sum[o] += (r - l + 1) * v;
        lazy[o] += v;
    }
    void pushdown (int o, int l, int r) {
        if (lazy[o]) {
            int mid = l + r >> 1;
            addtag(o << 1, l, mid, lazy[o]);
            addtag(o << 1 | 1, mid + 1, r, lazy[o]);
            lazy[o] = 0;
        }
    }
    void build (int o, int l, int r, const vector<ULL> &a) {
        if (l == r) {
            sum[o] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(o << 1, l, mid, a);
        build(o << 1 | 1, mid + 1, r, a);
        pushup(o);
    }
    void update (int o, int l, int r, int ql, int qr, ULL v) {
        if (ql <= l && r <= qr) {
            addtag(o, l, r, v);
            return;
        }
        pushdown(o, l, r);
        int mid = l + r >> 1;
        if (ql <= mid) update(o << 1, l, mid, ql, qr, v);
        if (qr > mid) update(o << 1 | 1, mid + 1, r, ql, qr, v);
        pushup(o);
    }
    ULL query (int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[o];
        pushdown(o, l, r);
        int mid = l + r >> 1;
        ULL res = 0;
        if (ql <= mid) res += query(o << 1, l, mid, ql, qr);
        if (qr > mid) res += query(o << 1 | 1, mid + 1, r, ql, qr);
        return res; 
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <ULL> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    SegmentTree tr1(n), tr2(n);
    tr1.build(1, 1, n, a);
    tr2.build(1, 1, n, b);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            tr2.update(1, 1, n, l, r, x);
            tr1.update(1, 1, n, l, r, -static_cast<ULL>(i) * x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << tr1.query(1, 1, n, l, r) + static_cast<ULL>(i) * tr2.query(1, 1, n, l, r) << '\n';
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}