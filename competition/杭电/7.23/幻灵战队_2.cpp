#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> L;
    auto f = [&](int x) -> int {
		return 20LL * x + 5LL * (1 + x) * x / 2;
    };
    auto g = [&](int x, int i) -> int {
		if (i == 0) return f(x);
        if (i == x) return 0;
        int p = (x - i) / (i + 1);
        int r = (x - i) % (i + 1);
        return r * f(p + 1) + (i + 1 - r) * f(p);
    };
    int ans = 0;
	int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        }
        else if (cur){
            ans += f(cur);
            L.push_back(cur);
            cur = 0;
        }
    }
    if (cur) L.push_back(cur), ans += f(cur);
    priority_queue <int> q;
    for (auto &x : L) {
        for (int i = 1; i <= x; i++) {
            q.push(g(x, i - 1) - g(x, i));
        }
    }
    int cnt = 0;
    while (!q.empty()) {
		if (cnt == k) break;
		ans -= q.top();
        q.pop();
		cnt++;
    }
    cout << ans << '\n';
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