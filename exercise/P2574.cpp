#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
struct SegmentTree {
    int n;
    vector<T> tree, lazy;
    SegmentTree(int n) : n(n), tree(4 * n + 1, 0), lazy(4 * n + 1, 0) {}
    void push_up(int node) {
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    void push_down(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            lazy[node * 2] ^= 1;
            tree[node * 2] = (mid - l + 1) - tree[node * 2];
            lazy[node * 2 + 1] ^= 1;
            tree[node * 2 + 1] = (r - mid) - tree[node * 2 + 1];
            lazy[node] = 0;
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
    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            lazy[node] ^= 1;
            tree[node] = (r - l + 1) - tree[node];
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);
        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);
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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
	}
	SegmentTree<int> tr(n);
	tr.build(a, 1, 1, n);
	for (int i = 1, op, l, r; i <= m; i++) {
		cin >> op >> l >> r;
 		if (op == 0) {
			tr.update(1, 1, n, l, r);
		}
		else {
			cout << tr.query(1, 1, n, l, r) << '\n';
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
