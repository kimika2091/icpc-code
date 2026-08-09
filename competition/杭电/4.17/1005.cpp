#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    int n;
    cin >> n;
    n ^= 1;
    int cnt = __builtin_popcount(n);
    cout << cnt << '\n';
}   

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}