#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	priority_queue<int> mx;
	priority_queue<int, vector<int>, greater<int>> mn;
	auto insert = [&](int x) -> void {
		if (mx.empty() || x <= mx.top()) mx.push(x);
		else mn.push(x);
		while (mx.size() > mn.size() + 1) {
			mn.push(mx.top());
			mx.pop();
		}
		while (mn.size() >= mx.size()) {
			mx.push(mn.top());
			mn.pop();
		}
	};
	auto query = [&]() -> void {
		cout << mx.top() << '\n';
	};
	int x;
	cin >> x;
	insert(x);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int a, b;
		cin >> a >> b;
		insert(a);
		insert(b);
		query();
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}