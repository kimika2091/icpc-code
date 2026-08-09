#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Segment {
    int l, r;
    int len() const { return r - l + 1; }
    bool operator < (const Segment &other) const {
        return l > other.l;
    }
};
struct Query {
    int l, r;
    int id;
    bool operator < (const Query &other) const {
        return l > other.l;
    }
};
struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void update(int x, int v) {
        for (int i = x; i <= n; i += i & -i) {
            t[i] = max(t[i], v);
        }
    }
    int query(int x) const {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res = max(res, t[i]);
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector <Segment> points(n);
    vector <int> Rs(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].l >> points[i].r;
        Rs[i] = points[i].r;
    }
    sort(Rs.begin(), Rs.end());
    Rs.erase(unique(Rs.begin(), Rs.end()), Rs.end());
    vector <Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
    sort(points.begin(), points.end());
    sort(queries.begin(), queries.end());
    vector <int> ans(q);
    BIT bit(Rs.size());
    int ptr = 0;
    for (auto &[L, R, id] : queries) {
        while (ptr < n && points[ptr].l >= L) {
            int len = points[ptr].len();
            int x = lower_bound(Rs.begin(), Rs.end(), points[ptr].r) - Rs.begin() + 1;
            bit.update(x, len);
            ptr++;
        }
        int x = upper_bound(Rs.begin(), Rs.end(), R) - Rs.begin();
        ans[id] = bit.query(x);
    }
    for (auto &x : ans) cout << x << '\n';
}   

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
}