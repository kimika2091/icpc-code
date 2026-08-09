#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> x(n), y(n);
    vector <int> cnt(n);
    set <pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        st.insert({x[i], i});
    }
    while (m--) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        // cout << l << ' ' << r << ' ' << u << ' ' << v << '\n';
        auto it = st.lower_bound({l, -1});
        vector <pair<int, int>> tmp;
        while (it != st.end() && it->first <= r) {
            int id = it->second;
            // cout << id << '\n';
            auto cur = it;
            it++;
            cnt[id]++;
            x[id] += u;
            y[id] += v;
            st.erase(cur);
            if (cnt[id] < 6) tmp.push_back({x[id], id});
        }
        for (auto &p : tmp) st.insert(p);
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 6) cout << "Disappeared\n";
        else if (cnt[i] == 0) cout << "Cumulus " << x[i] << ' ' << y[i] << '\n';
        else cout << "Cirrus " << x[i] << ' ' << y[i] << '\n';
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}