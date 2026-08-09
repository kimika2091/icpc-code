#include <bits/stdc++.h>
using namespace std;
#define int long long

array <uint32_t, 26> pre, e;
array <array<uint32_t, 27>, 27> C;
unordered_map <uint32_t, uint32_t> dp;

uint32_t mul(uint32_t x, uint32_t y) {
    return uint32_t(uint64_t(x) * y);
}

uint32_t dfs(uint32_t S) {
    if (__builtin_popcount(S) <= 1) return 1;
    if (dp.count(S)) return dp[S];

    vector <uint32_t> parts;
    uint32_t rest = S;
    while (rest) {
        uint32_t cur = rest & -rest;
        uint32_t part = 0;
        while (cur) {
            part |= cur;
            uint32_t nxt = 0;
            uint32_t t = cur;
            while (t) {
                int x = __builtin_ctz(t);
                t &= t - 1;
                nxt |= e[x];
            }
            cur = nxt & S & ~part;
        }
        parts.push_back(part);
        rest &= ~part;
    }

    if (parts.size() > 1) {
        uint32_t ans = 1;
        int sum = 0;
        for (auto &part : parts) {
            int sz = __builtin_popcount(part);
            ans = mul(ans, C[sum + sz][sz]);
            ans = mul(ans, dfs(part));
            sum += sz;
        }
        return dp[S] = ans;
    }

    uint32_t source = 0;
    uint32_t t = S;
    while (t) {
        int x = __builtin_ctz(t);
        t &= t - 1;
        if ((pre[x] & S) == 0) source |= uint32_t(1) << x;
    }
    if (source == 0) return dp[S] = 0;
    if ((source & (source - 1)) == 0) return dp[S] = dfs(S ^ source);

    uint32_t ans = 0;
    while (source) {
        uint32_t x = source & -source;
        source &= source - 1;
        ans += dfs(S ^ x);
    }
    return dp[S] = ans;
}

void solve() {
    C[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    string s;
    cin >> s;
    int n = s.size();
    vector <int32_t> z(n);
    pre.fill(0);
    e.fill(0);
    dp.clear();

    int l = 0, r = -1;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min<int>(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (i + z[i] == n) {
            cout << 0 << '\n';
            return;
        }
        int x = s[z[i]] - 'a';
        int y = s[i + z[i]] - 'a';
        pre[y] |= uint32_t(1) << x;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (pre[j] >> i & 1) {
                e[i] |= uint32_t(1) << j;
                e[j] |= uint32_t(1) << i;
            }
        }
    }

    cout << dfs((uint32_t(1) << 26) - 1) << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    solve();
    return 0;
}
