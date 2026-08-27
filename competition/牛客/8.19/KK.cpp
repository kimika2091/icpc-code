#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, full;
int a[25][25], w[1 << 24], dp[1 << 24];
int dfs(int status) {
    if (dp[status] != -1e18) return dp[status];
    if (status == full) {
        return dp[status] = 0;
    }
    int valid = full ^ status;
    int a = __builtin_ctzll(valid), mx = -1e18;
    valid ^= (1 << a);
    for (int bs = valid; bs; bs &= bs - 1) {
        int b = __builtin_ctzll(bs);
        for (int cs = bs & (bs - 1); cs; cs &= cs - 1) {
            int c = __builtin_ctzll(cs);
            int cur = (1 << a) | (1 << b) | (1 << c);
            mx = max(mx, dfs(status | cur) + w[cur]);
        }
    }
    return dp[status] = mx; 
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    m = 3 * n;
    full = (1 << m) - 1;
    for (int i = 0; i <= full; i++) dp[i] = -1e18;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int cur = (1 << i) | (1 << j) | (1 << k);
                w[cur] = a[i][j] + a[i][k] + a[j][k]; 
            }
        }
    }
    cout << dfs(0) << '\n';
    return 0;
}