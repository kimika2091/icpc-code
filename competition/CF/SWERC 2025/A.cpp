#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    map <int, int> f;
    for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]] ++;
    int ans = 0, cur = 0;
    for (auto [num, cnt] : f) {
        if (cnt > k) {
            cur ++;
            f[num + 1] += cnt - 1;
            ans = max(ans, cur);
        }
        else {
            cur = 0;
        }
    }
    ans = max(ans, cur);
    cout << ans << '\n';
}   

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}