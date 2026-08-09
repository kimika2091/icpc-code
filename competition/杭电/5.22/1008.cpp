#include <bits/stdc++.h>
using namespace std;
#define int long long

void print(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    sort(a.begin(), a.end(), greater<int>());
    __int128 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (n - 1 - i) * a[i];
    }
    print(ans);
    cout << '\n'; 
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}