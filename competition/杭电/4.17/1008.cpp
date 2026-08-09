#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    int n, k;
    cin >> n >> k;
    vector <ll> a(n + 1), pre(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    deque <int> q;
    auto cost = [&](ll j) -> ll {
        return f[j - 1] + a[j] - pre[j] / 2;
    };
    for (int i = 1; i <= n; i++) {
        while(!q.empty() && q.front() < i - k) q.pop_front();
        f[i] = f[i - 1] + a[i];
        if (!q.empty()) {
            int j = q.front();
            f[i] = min(f[i], pre[i] / 2 + cost(j));
        }
        while (!q.empty() && cost(q.back()) >= cost(i)) q.pop_back();
        q.push_back(i);
    }
    cout << f[n] << '\n';
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