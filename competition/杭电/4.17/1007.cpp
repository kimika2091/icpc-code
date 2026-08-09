#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
    int l, r;
    ll val;
    bool operator < (const Node &o) const {
        return l < o.l;
    }
};
set <Node> seg;
vector <ll> ans;
auto split(int pos) {
    auto it = seg.lower_bound({pos, 0, 0});
    if (it != seg.end() && it->l == pos) return it;
    it--;
    auto [l, r, v] = *it;
    seg.erase(it);
    seg.insert({l, pos - 1, v});
    return seg.insert({pos, r, v}).first;
}
void assign(int l, int r, int val) {
    auto itr = split(r + 1), itl = split(l);
    seg.erase(itl, itr);
    seg.insert({l, r, val});
}
void add(int l, int r, ll x) {
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; it++) {
        auto [l, r, v] = *it;
        if (v) {
            ans[v] += (r - l + 1) * x;
        }
    }
}
void solve () {
    int n, m, q;
    cin >> n >> m >> q;
    vector <ll> a(n + 1);
    ans.assign(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    seg.clear();
    int lst = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[lst]) {
            seg.insert({lst, i - 1, a[lst]});
            lst = i;
        }
    }
    seg.insert({lst, n, a[lst]});
    while (q--) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        if (op == 1) {
            assign(l, r, x);
        }
        else {
            add(l, r, x);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " \n"[i == m];
    }
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}