#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	auto calc = [&](vector <int> a, int x) -> double {
		int cnt = 0;
		for (int i : a) {
			if (i == x) cnt++;
		}
		return cnt / 6.0;
	};
	vector <int> a(6), b(6), c(6);
	for (int i = 0; i < 6; i++) cin >> a[i];
	for (int i = 0; i < 6; i++) cin >> b[i];
	for (int i = 0; i < 6; i++) cin >> c[i];
	double ans = 0;
	ans += calc(a, 4) * calc(b, 5) * calc(c, 6);
	ans += calc(a, 4) * calc(b, 6) * calc(c, 5);
	ans += calc(a, 5) * calc(b, 4) * calc(c, 6);
	ans += calc(a, 5) * calc(b, 6) * calc(c, 4);
	ans += calc(a, 6) * calc(b, 4) * calc(c, 5);
	ans += calc(a, 6) * calc(b, 5) * calc(c, 4);
	cout << fixed << setprecision(10) << ans << endl;
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
