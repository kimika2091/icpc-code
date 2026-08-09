#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5;

int c[N + 5];

void solve() {
	int n;
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		c[1] ++;
		c[x + 1] --;
	}
	int top = 1;
	while (c[top]) {
		c[top + 1] += c[top];
		top ++;
	}
	top = 1;
	while (c[top]) {
		int x = c[top] / 10;
		c[top] %= 10;
		c[++top] += x;
	}
	top--;
	for (int i = top; i >= 1; i--) cout << c[i];
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
