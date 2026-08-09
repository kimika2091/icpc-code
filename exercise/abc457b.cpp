#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector <int> l(n + 1);
	vector <vector<int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	int x, y;
	cin >> x >> y;
	cout << a[x][y - 1] << '\n';
	
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
