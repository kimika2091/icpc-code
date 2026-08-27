#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> zfunction (const string &s) {
	int n = s.size();
	vector <int> pi(n);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j != 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

void solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	string s;
	cin >> s;
	auto pi1 = zfunction(s);
	reverse(s.begin(), s.end());
	auto pi2 = zfunction(s);
	reverse(s.begin(), s.end());
	for (int r1 = 0; r1 < n; r1++) {

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