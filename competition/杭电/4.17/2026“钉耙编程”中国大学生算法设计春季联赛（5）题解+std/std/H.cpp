#include <bits/stdc++.h>
using namespace std;

void sc() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> a(n + 1), S(n + 1, 0), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        S[i] = S[i - 1] + a[i];
    }
    dp[1] = a[1];
    auto val = [&](int j) { return dp[j] - S[j] / 2; };
    deque<int> dq;
    dq.push_back(1);
    for (int i = 2; i <= n; i++) {
        while (!dq.empty() && dq.front() < max(1, i - k - 1)) dq.pop_front();
        dp[i] = a[i] + S[i - 1] / 2 + val(dq.front());
        while (!dq.empty() && val(dq.back()) >= val(i)) dq.pop_back();
        dq.push_back(i);
    }
    long long ans = LLONG_MAX;
    for (int f = max(1, n - k); f <= n; f++)
        ans = min(ans, dp[f] + (S[n] - S[f]) / 2);
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) sc();
    return 0;
}
