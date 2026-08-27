#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegmentTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    struct Node {
        int L, R, cnt;
        int tag1, tag2;
        friend Node operator + (const Node &l, const Node &r) {
            return {l.L, r.R, l.cnt + r.cnt + (l.R != r.L), -1, 0};
        }
    };
    vector <Node> tree;
    SegmentTree(int n) : tree(n * 4 + 1) {}
    void addtag1 (int rt, int x) {
        tree[rt].L = tree[rt].R = x;
        tree[rt].cnt = 0;
        tree[rt].tag1 = x;
        tree[rt].tag2 = 0;
    }
    void addtag2 (int rt) {
        tree[rt].L ^= 1;
        tree[rt].R ^= 1;
        if (tree[rt].tag1 != -1) {
            tree[rt].tag1 ^= 1;
        }
        else {
            tree[rt].tag2 ^= 1;
        }
    }
    void pushup (int rt) {
        tree[rt] = tree[ls] + tree[rs];
    }
    void pushdown (int rt) {
        if (tree[rt].tag1 != -1) {
            addtag1(ls, tree[rt].tag1);
            addtag1(rs, tree[rt].tag1);
            tree[rt].tag1 = -1;
        }
        if (tree[rt].tag2 != 0) {
            addtag2(ls);
            addtag2(rs);
            tree[rt].tag2 = 0;
        }
    }
    void build (const vector<int> &a, int rt, int l, int r) {
        tree[rt].tag1 = -1;
        tree[rt].tag2 = 0;
        if (l == r) {
            tree[rt].L = tree[rt].R = a[l];
            tree[rt].cnt = 0;
            return;
        }
        int mid = l + r >> 1;
        build(a, ls, l, mid);
        build(a, rs, mid + 1, r);
        pushup(rt);
    }
    void assign (int rt, int l, int r, int ql, int qr, int x) {
        if (ql <= l && r <= qr) {
            addtag1(rt, x);
            return;
        }
        pushdown(rt);
        int mid = l + r >> 1;
        if (ql <= mid) assign(ls, l, mid, ql, qr, x);
        if (qr > mid) assign(rs, mid + 1, r, ql, qr, x);
        pushup(rt);
    }
    void flip (int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            addtag2(rt);
            return;
        }
        pushdown(rt);
        int mid = l + r >> 1;
        if (ql <= mid) flip(ls, l, mid, ql, qr);
        if (qr > mid) flip(rs, mid + 1, r, ql, qr);
        pushup(rt);
    }
    Node query (int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[rt];
        }
        pushdown(rt);
        int mid = l + r >> 1;
        if (qr <= mid) return query(ls, l, mid, ql, qr);
        if (ql > mid) return query(rs, mid + 1, r, ql, qr);
        return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
    }
    #undef ls
    #undef rs
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SegmentTree tr(n);
    tr.build(a, 1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int x;
            cin >> x;
            tr.assign(1, 1, n, l, r, x);
        }
        else if (op == 2) {
            tr.flip(1, 1, n, l, r);
        }
        else {
            cout << tr.query(1, 1, n, l, r).cnt << '\n';
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