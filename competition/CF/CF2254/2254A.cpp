#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	auto check = [&]() {
		if (a == b || b == c || c == a) return 1;
		return 0;
	};
	auto move = [&]() {
		vector <int> A = {a, b, c};
		sort(A.begin(), A.end());
		a = A[0], b = A[1], c = A[2];
		a++;
		c--;
	};
	int cnt = 0;
	while (!check()) {
		move();
		cnt++;
	}
	cout << cnt << '\n';
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