#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int inv2 = 500000004;

int qpow (int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            c = c * a % MOD;
        }
    }
    return c;
}
int inv(int x) {return qpow(x, MOD - 2);}


void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (ans + (a[i].second + a[i].first) * inv2 % MOD - (a[i - 1].second + a[i - 1].first) * inv2 % MOD + MOD) % MOD;
    }
    cout << ans << '\n';
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
