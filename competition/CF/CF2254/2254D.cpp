#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    map<ll, int> f;
    for (ll &x : b) {
        cin >> x;
        ++f[x];
    }
    vector<pair<ll, int>> groups;
    for (auto [shadow, count] : f) {
        groups.push_back({shadow, count});
    }
    int m = groups.size();
    if (groups[0].first != 0) {
        cout << -1 << '\n';
        return;
    }
    vector<ll> val(m);
    for (int i = 0; i + 1 < m; ++i) {
        ll difference = groups[i + 1].first - groups[i].first;
        ll count = groups[i].second;
        if (difference % count != 0) {
            cout << -1 << '\n';
            return;
        }
        val[i] = difference / count;
        if (val[i] <= 0 ||
            (i > 0 && val[i] <= val[i - 1])) {
            cout << -1 << '\n';
            return;
        }
    }
    if (m == 1) {
        val[0] = 1;
    } else {
        val[m - 1] = val[m - 2] + 1;
    }
    if (val[m - 1] > (ll)1e18) {
        cout << -1 << '\n';
        return;
    }
    map<ll, ll> p;
    for (int i = 0; i < m; ++i) {
        p[groups[i].first] = val[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << p[b[i]] << " \n"[i == n - 1];
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