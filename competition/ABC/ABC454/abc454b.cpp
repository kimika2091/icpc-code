#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), f(m + 1);
	bool f1 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (f[a[i]]) f1 = 0;
		f[a[i]] = 1;
	}
	set <int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(a[i]);
	}
	bool f2 = s.size() == m;
	cout << (f1? "Yes":"No") <<'\n';
	cout << (f2? "Yes":"No") <<"\n";
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
