#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2000005;

int n, m, Q;
int a[N];
ll ans[N];

int tl[N << 2], tr[N << 2], col[N << 2];
ll tag[N << 2];

void push_up(int k) {
    col[k] = (col[k << 1] == col[k << 1 | 1]) ? col[k << 1] : -1;
}

void do_apply(int k, ll v) {
    if (col[k] != -1)
        ans[col[k]] += v * (tr[k] - tl[k] + 1);
    else
        tag[k] += v;
}

void push_down(int k) {
    if (tag[k]) {
        do_apply(k << 1, tag[k]);
        do_apply(k << 1 | 1, tag[k]);
        tag[k] = 0;
    }
    if (col[k] != -1) {
        col[k << 1] = col[k << 1 | 1] = col[k];
        col[k] = -1;
    }
}

void build(int k, int l, int r) {
    tl[k] = l; tr[k] = r; tag[k] = 0;
    if (l == r) { col[k] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    push_up(k);
}

void modify_assign(int k, int l, int r, int c) {
    if (tl[k] >= l && tr[k] <= r) { col[k] = c; return; }
    push_down(k);
    int mid = (tl[k] + tr[k]) >> 1;
    if (l <= mid) modify_assign(k << 1, l, r, c);
    if (r > mid) modify_assign(k << 1 | 1, l, r, c);
    push_up(k);
}

void modify_add(int k, int l, int r, int v) {
    if (tl[k] >= l && tr[k] <= r) { do_apply(k, v); return; }
    push_down(k);
    int mid = (tl[k] + tr[k]) >> 1;
    if (l <= mid) modify_add(k << 1, l, r, v);
    if (r > mid) modify_add(k << 1 | 1, l, r, v);
    push_up(k);
}

void flush_tree(int k) {
    if (tl[k] == tr[k]) return;
    push_down(k);
    flush_tree(k << 1);
    flush_tree(k << 1 | 1);
}

void sc() {
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) ans[i] = 0;
    build(1, 1, n);
    while (Q--) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        if (op == 1) modify_assign(1, l, r, x);
        else modify_add(1, l, r, x);
    }
    flush_tree(1);
    for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) sc();
    return 0;
}
