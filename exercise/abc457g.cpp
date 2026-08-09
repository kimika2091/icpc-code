#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
	int a, b;
	bool operator < (const node & other) const {
		return a != other.a ? a > other.a : b < other.b;
	}
};

void solve() {
	int n;
	cin >> n;
	vector <node> c(n + 1);
	for (int i = 1; i <= n; i++) {
		int t, x;
		cin >> t >> x;
		c[i] = {x - t, x + t};
	}
	sort(c.begin() + 1, c.end());
	vector <int> d;
	for (auto &[a, b] : c) {
		auto it = lower_bound(d.begin(), d.end(), -b);
		if (it == d.end()) d.push_back(-b);
		else *it = -b;
	}
	cout << d.size() << '\n';
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
