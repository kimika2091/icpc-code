#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mask = 0;
    bool s10 = false;
    bool s20 = false;
    bool s21 = false;
    bool s210 = false;
};

bool has(const Node& x, int value) {
    return (x.mask >> value) & 1;
}

Node merge(const Node& L, const Node& R) {
    Node res;
    res.mask = L.mask | R.mask;
    res.s10 = L.s10 || R.s10 || (has(L, 1) && has(R, 0));
    res.s20 = L.s20 || R.s20 || (has(L, 2) && has(R, 0));
    res.s21 = L.s21 || R.s21 || (has(L, 2) && has(R, 1));
    res.s210 = L.s210 || R.s210 || (L.s21 && has(R, 0)) || (has(L, 2) && R.s10);
    return res;
}

Node makeNode(int value) {
    Node res;
    res.mask = 1 << value;
    return res;
}

struct SegmentTree {
    int size;
    vector<Node> tree;
    SegmentTree(const vector<int>& a) {
        int n = a.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(size * 2);
        for (int i = 0; i < n; ++i) {
            tree[size + i] = makeNode(a[i]);
        }
        for (int i = size - 1; i >= 1; --i) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }
    void update(int pos, int value) {
        int p = size + pos;
        tree[p] = makeNode(value);
        for (p >>= 1; p >= 1; p >>= 1) {
            tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
        }
    }
    Node query(int l, int r) {
        l += size;
        r += size;
        Node L, R;
        while (l <= r) {
            if (l & 1) L = merge(L, tree[l++]);
            if (!(r & 1)) R = merge(tree[r--], R);
            l >>= 1;
            r >>= 1;
        }
        return merge(L, R);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    SegmentTree seg(a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            seg.update(p, x);
        } 
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            Node res = seg.query(l, r);
            bool sorted = !res.s10 && !res.s20 && !res.s21;
            if (sorted) cout << 0 << '\n';
            else if (res.s210) cout << 2 << '\n';
            else cout << 1 << '\n';         
        }
    }
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}