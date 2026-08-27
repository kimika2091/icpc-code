#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    struct Node {
        bool has_0 = 0, has_1 = 0, has_2 = 0;
        bool has_21 = 0, has_20 = 0, has_10 = 0;
        bool has_210 = 0;
        bool order = 0;
        friend Node operator + (const Node &l, const Node &r) {
            return {
                l.has_0 | r.has_0, l.has_1 | r.has_1, l.has_2 | r.has_2, 
                l.has_21 | r.has_21 | (l.has_2 & r.has_1), l.has_20 | r.has_20 | (l.has_2 & r.has_0), l.has_10 | r.has_10 | (l.has_1 & r.has_0), 
                l.has_210 | r.has_210 | (l.has_2 & r.has_10) | (l.has_21 & r.has_0), 
                l.order & r.order & !(l.has_1 & r.has_0) & !(l.has_2 & r.has_0) & !(l.has_2 & r.has_1)
            };
        }
    };
    vector <Node> tree;
    SegmentTree (int n) : tree(n << 2 | 1) {}
    void pushup (int rt) {
        tree[rt] = tree[ls] + tree[rs];
    }
    void build (const vector<int> &a, int rt, int l, int r) {
        if (l == r) {
            if (a[l] == 0) tree[rt].has_0 = 1;
            else if (a[l] == 1) tree[rt].has_1 = 1;
            else tree[rt].has_2 = 1;
            tree[rt].order = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(a, ls, l, mid);
        build(a, rs, mid + 1, r);
        pushup(rt);
    }
    void update (int rt, int l, int r, int p, int x) {
        if (l == r) {
            tree[rt].has_0 = tree[rt].has_1 = tree[rt].has_2 = 0;
            if (x == 0) tree[rt].has_0 = 1;
            else if (x == 1) tree[rt].has_1 = 1;
            else tree[rt].has_2 = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(ls, l, mid, p, x);
        else update(rs, mid + 1, r, p, x);
        pushup(rt);
    }
    Node query (int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[rt];
        }
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(ls, l, mid, ql, qr);
        if (ql > mid) return query(rs, mid + 1, r, ql, qr);
        return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
    }
    #undef ls
    #undef rs
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SegmentTree tr(n);
    tr.build(a, 1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            tr.update(1, 1, n, x, y);
        }
        else {
            auto res = tr.query(1, 1, n, x, y);
            if (res.order) cout << 0 << '\n';
            else if (res.has_210) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}