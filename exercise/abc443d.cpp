#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <ll> R(n + 1);
	ll sum = 0;
	for (int i = 1; i <= n; i++) cin >> R[i], sum += R[i];
	for (int i = 2; i <= n; i++) R[i] = min(R[i - 1] + 1, R[i]);
	for (int i = n - 1; i >= 1; i--) R[i] = min(R[i], R[i + 1] + 1);
	for (int i = 1; i <= n; i++) sum -= R[i];
	cout << sum << '\n';
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
