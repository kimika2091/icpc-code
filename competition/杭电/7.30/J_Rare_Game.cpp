#include<bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );
    vector<array<ULL, 4>> rnd(n + 1);
    for (int x = 1; x <= n; x++) {
        rnd[x][0] = 0;
        for (int r = 1; r < 4; r++) {
            rnd[x][r] = rng();
        }
    }
    
    vector<int> r(n + 1), dp(n + 1);
    vector<vector<int>> o(n + 1);
    vector<ULL> h(n + 1);
    unordered_map<ULL, int> sum;
    sum.reserve(2 * n + 10);
    sum.max_load_factor(0.7);
    dp[0] = 1;
    h[0] = 0;
    sum[h[0]] = 1;
    int lim = 0, left = 0;
    ULL cur = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        cur ^= rnd[x][r[x]];
        r[x] = (r[x] + 1) % 4;
        cur ^= rnd[x][r[x]];
        h[i] = cur;
        o[x].push_back(i);
        int k = o[x].size();
        if (k >= 5) {
            lim = max(lim, o[x][k - 5]);
        }
        while (left < lim) {
            int &val = sum[h[left]];
            val -= dp[left];
            if (val < 0) val += MOD;
            left++;
        }
        dp[i] = sum[h[i]];
        int &val = sum[h[i]];
        val += dp[i];
        if (val >= MOD) val -= MOD;
    }
    cout << dp[n] << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0; 
}
