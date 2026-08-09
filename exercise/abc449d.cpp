#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;

vector <int> cnt_y(N + 5);
vector <ll> pre_y(N + 5), suf_even_y(N + 5);

void solve() {
	int L, R, D, U;
	cin >> L >> R >> D >> U;
	for (int i = D; i <= U; i++) cnt_y[abs(i)] ++;
	pre_y[0] = cnt_y[0];
	for (int i = 1; i <= N; i++) {
		pre_y[i] = pre_y[i - 1] + cnt_y[i];
	}
	suf_even_y[N] = cnt_y[N];
	for (int i = N - 1; i >= 0; i--) {
		if (i & 1) suf_even_y[i] = suf_even_y[i + 1];
		else suf_even_y[i] = suf_even_y[i + 1] + cnt_y[i];
	}
	// cout << pre_even_y[0] << '\n';
	ll ans = 0;
	for (int i = L; i <= R; i++) {
		int x = abs(i);
		if (x & 1) {
			ans += suf_even_y[x];
		}
		else {
			ans += suf_even_y[x + 1] + pre_y[x];
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
