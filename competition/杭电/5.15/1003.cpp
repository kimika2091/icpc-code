#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        ans -= x;
        ans = max(ans, 0ll);
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}