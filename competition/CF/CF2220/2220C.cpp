#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check (ll x, ll p) {
	for(ll i = 3; i * i <= x; i++) {
		if (x % i == 0) {
			ll M = i, N = x / i;
			if (N > M) swap(N, M);
			if (N >= 3 && M % 2 && N % 2){
				M /= 2, N /= 2;
				if (p >= M - N){
					cout << N << ' ' << M << '\n';
					return true;
				}  
			}
		} 
	}
	return false;
}
void solve() {
	ll p, q;
	cin >> p >> q;
	ll tot = p + q * 2; 
	tot = tot * 2 + 1;// 2*tot+1=(2m+1)(2n+1)
	if (!check(tot, p)) {
		cout << "-1" <<'\n';
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
