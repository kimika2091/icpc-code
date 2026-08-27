#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), pre(n + 1);
    vector <vector<int>> dp(n + 2, vector<int>(2));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for (int i = n; i >= 1; i--) {
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][1] = a[i] + max(dp[i + 1][1], 0LL);
    }
    int ans = *max_element(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i] + max(dp[i + 1][0], dp[i + 1][1]));
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