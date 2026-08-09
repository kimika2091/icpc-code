#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int P = 998244353;

void solve() {
	ll n, x;
	cin >> n >> x;
	// s(i) = i, 1, i+1, 0  
	auto count_mod4 = [](ll m, int r) -> ll {
		return ((m + 4 - r) / 4 + (r == 3)) % P;
	};
	ll c1 = count_mod4(x - 1, 1) * (count_mod4(n, 1) - count_mod4(x - 1, 1) + P) % P;
	ll c2 = count_mod4(x - 1, 3) * (count_mod4(n, 3) - count_mod4(x - 1, 3) + P) % P;
	cout << (c1 + c2 + P) % P << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
