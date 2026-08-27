#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int N = 3 * n;
    vector <vector<int>> a(N, vector<int>(N));
    vector <vector<vector<int>>> w(N, vector<vector<int>>(N, vector<int>(N)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                w[i][j][k] = a[i][j] + a[i][k] + a[j][k];
            }
        }
    }
    int full = (1 << N) - 1;
    vector <int> dp(full + 1, -1e18);
    dp[0] = 0;
    auto work = [&](int mask) -> void {
        vector <int> p;
        for (int i = 0; i < N; i++) {
            if (mask >> i & 1) {
                p.push_back(i);
            }
        }
        int m = p.size();
        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                dp[mask] = max(dp[mask], dp[mask ^ ((1 << p[0]) | (1 << p[i]) | (1 << p[j]))] + w[p[0]][p[i]][p[j]]);
            }
        }
    };
    auto choose = [&](int k) -> void {
        int cur = (1 << k) - 1;
        while (cur <= full) {
            work(cur);
            int lb = cur & -cur;
            int r = cur + lb;
            cur = r + ((cur ^ r) / lb >> 2);
        }
    };
    for (int i = 3; i <= N; i += 3) {
        choose(i);  
    }
    cout << dp[full] << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}