#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    ll n, t, S;
    cin >> n >> t >> S;
    if (S > ((1 << t) -1) * n) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
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