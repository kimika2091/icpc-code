#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m;
    cin >> n >> m;
    vector <double> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    
    auto solve1 = [&]() -> int {
        int B = a[1];
        int ans = 0;
        B += m;
        if (a[2] > B) ans++;
        for (int i = 3; i <= 2 * n; i += 2) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
            if (a[i + 1] > B) {
                ans++;
                ans += a[i] > B;
            }
            else if (a[i + 1] == B) {
                ans += a[i] + m > B;
            }
            else {
                if (B - a[i + 1] + B - a[i] < m) {
                    ans++;
                }
            }
        }
        return ans;
    };
    auto solve2 = [&]() -> int {
        int B = a[1];
        int ans = 0;
        if (a[2] + m > B) ans++;
        for (int i = 3; i <= 2 * n; i += 2) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
            if (a[i + 1] > B) {
                ans++;
                ans += a[i] + m > B;
            }
            else if (a[i + 1] == B) {
                ans++;
                ans += a[i] + m > B;   
            }
            else {
                if (B - a[i + 1] < m) {
                    ans++;
                    if (B - a[i] < m - (B - a[i + 1])) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    };
    cout << solve1() << ' ' << solve2() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}