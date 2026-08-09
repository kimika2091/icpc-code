#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        ll total = 0;
        int max_a = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            total += a[i];
            max_a = max(max_a, a[i]);
        }
        vector<int> last(max_a + 2, 0); 
        for (int i = 1; i <= n; ++i) {
            last[a[i]] = i;
        }
        vector<int> M(max_a + 2, 0);
        int cur = 0;
        for (int h = 1; h <= max_a; ++h) {
            cur = max(cur, last[h - 1]);
            M[h] = cur;
        }
        ll sumM = 0;
        for (int h = 1; h <= max_a; ++h) sumM += M[h];
        ll base = total - 1LL * n * max_a + sumM;
        ll ans = base;
        for (int i = 1; i <= n; ++i) {
            int v = a[i];
            ll cand = base;
            if (i > M[v]) {
                cand += (i - M[v] - 1);
            } else {
                cand -= 1;
            }
            ans = max(ans, cand);
        }
        cout << ans << '\n';
    }
    return 0;
}