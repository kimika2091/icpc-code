#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
struct SegmentTree {
    int n;
    vector<T> tree;
    SegmentTree(int n) : n(n), tree(4 * n + 1, 0) {}
    void push_up(int node) {
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int node, int l, int r, int x, T val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
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
        T res = 0;
        if (ql <= mid)
            res = max(res, query(node * 2, l, mid, ql, qr));
        if (qr > mid)
            res = max(res, query(node * 2 + 1, mid + 1, r, ql, qr));
        return res;
    }
};

void solve() {
	ll M, D;
	cin >> M >> D;
	SegmentTree<ll> tr(M);
	ll siz = 0, lst = 0;
	for (int i = 1; i <= M; i++) {
		char c;
        ll x;
		cin >> c >> x;
		if (c == 'Q') {
			lst = tr.query(1, 1, M, siz - x + 1, siz);
			cout << lst << '\n';
		}
		else {
			x = (x + lst) % D;
			siz++;
			tr.update(1, 1, M, siz, x);
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
