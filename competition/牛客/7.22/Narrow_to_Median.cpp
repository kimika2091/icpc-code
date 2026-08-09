#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    if (k & 1) {
        int mx = -1e18;
        for (int i = 1; i <= n; i++) {
            int L = i - (k - 1) / 2, R = i + (k - 1) / 2;
            if (L >= 1 && R <= n) mx = max(mx, k * a[i] - (s[R] - s[L - 1]));
        }
        cout << s[n] + mx << '\n';
    }
    else {
        int mx = -1e18;
        for (int i = 1; i < n; i++) {
            int L = i - (k - 2) / 2, R = i + 1 + (k - 2) / 2;
            if (L >= 1 && R <= n) mx = max(mx, k * (a[i] + a[i + 1]) / 2 - (s[R] - s[L - 1]));
        }
        cout << s[n] + mx << '\n';
    }
    
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
