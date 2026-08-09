#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, D;
	cin >> n >> D;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	multiset <int> s;
	int r = 1;
	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		bool flag = true;
		while (r <= n) {
			if (s.empty()) {
				s.insert(a[r]);
				r++;
				continue;
			}
			auto it = s.lower_bound(a[r]);	
			if (it == s.begin()) {
				if (*s.begin() - a[r] < D) {
					flag = false;
				}
			}
			else if (it == s.end()) {
				if (a[r] - *s.rbegin() < D) {
					flag = false;
				}
			}
			else {
				if (a[r] - *prev(it) < D || *it - a[r] < D) {
					flag = false;
				}
			}
			if (flag == false) break;
			s.insert(a[r]);
			r++;
		}
		ans += r - l;
		s.erase(a[l]);
	}
	assert(s.size() == 0);
	cout << ans;
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
