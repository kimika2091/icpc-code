#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int reducedSize = 1 << (m - 1);
    vector<vector<int64>> sum(m, vector<int64>(reducedSize));
    vector<int64> times(m);

    auto eraseBit = [](int mask, int bit) {
        int low = mask & ((1 << bit) - 1);
        int high = mask >> (bit + 1);
        return low | (high << bit);
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> times[j];

        string result;
        cin >> result;

        int rejected = 0;
        for (int j = 0; j < m; ++j) {
            if (result[j] == 'R') rejected |= 1 << j;
        }

        for (int j = 0; j < m; ++j) {
            sum[j][eraseBit(rejected, j)] += times[j];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int bit = 0; bit < m - 1; ++bit) {
            for (int mask = 0; mask < reducedSize; ++mask) {
                if (mask & (1 << bit)) {
                    sum[j][mask] += sum[j][mask ^ (1 << bit)];
                }
            }
        }
    }

    int fullSize = 1 << m;
    int reducedFull = reducedSize - 1;
    const int64 inf = numeric_limits<int64>::max() / 4;
    vector<int64> dp(fullSize, inf);
    dp[0] = 0;

    for (int mask = 0; mask < fullSize; ++mask) {
        for (int j = 0; j < m; ++j) {
            if (mask & (1 << j)) continue;
            int reducedMask = eraseBit(mask, j);
            int64 extra = sum[j][reducedFull ^ reducedMask];
            int nextMask = mask | (1 << j);
            dp[nextMask] = min(dp[nextMask], dp[mask] + extra);
        }
    }

    cout << dp[fullSize - 1] << '\n';
    return 0;
}
