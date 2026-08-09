#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	int N = (1 << n) - 1;
	string s;
	cin >> s;
	vector <int> a(N + 1), b(N + 1);
	for (int i = 1; i <= N; i++) {
		a[i] = s[i - 1] - '0';
	}
	int pos = -1;
	for (int i = 1; i <= N; i++) {
		if (a[i] == 0) continue;
		if (pos == -1) {
			pos = i;
			continue;
		}
		b[i] = pos;
		int z = i ^ pos;
		a[i] ^= 1;
		a[pos] ^= 1;
		a[z] ^= 1;
		if (z > i) pos = -1;
		else pos = z;
	}
	for (int i = 1; i <= N; i++) {
		cout << b[i] << " \n"[i == N];
	}
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