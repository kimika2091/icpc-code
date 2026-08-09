#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1), s(n + 1), f(100 + 1);
	bool flag = 1;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
		if (f[a[i]]) flag = 0;
		f[a[i]] = 1;
	}
	if (!flag){
		cout << "-1" << '\n';
		return;
	}
	sort(a.begin() + 1, a.end(),[&](int x, int y){return x > y;});
	for (int i = 1;i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	
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
