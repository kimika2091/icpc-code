#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n + 1), odd, even;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (i & 1) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	sort(odd.begin(), odd.end(),[](int x, int y){return x > y;});
	sort(even.begin(), even.end(),[](int x, int y){return x > y;});
	int cnt_odd = 0, cnt_even = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (x & 1) cnt_odd++;
		else cnt_even++;
	}
	ll mark = 0;
	bool f1 = 0;
	for (int i = 0; i < min((int)odd.size(), cnt_odd); i++) if (!f1 || odd[i] > 0) mark += odd[i], f1 = 1;
	bool f2 = 0;
	for (int i = 0; i < min((int)even.size(), cnt_even); i++) if (!f2 || even[i] > 0) mark += even[i], f2 = 1;
	cout << sum - mark << '\n';
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
