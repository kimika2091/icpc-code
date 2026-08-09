#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	ll sum = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) cnt0++;
		if (a[i] == 1) cnt1++;
		if (a[i] == 2) cnt2++;
	}
	
	cout << cnt0 + min(cnt1, cnt2) + (abs(cnt1 - cnt2) / 3) << '\n';
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