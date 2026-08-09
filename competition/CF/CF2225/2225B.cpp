#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	auto check = [&](string t) -> bool {
		int p1 = 0, p2 = n - 1;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				p1 = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] != t[i]) {
				p2 = i;
				break;
			}
		}
		string tmp1, tmp2, res;
		for (int i = p1; i <= p2; i++) tmp1 += s[i], res += t[i];
		reverse(tmp1.begin(), tmp1.end());
		for (char c : tmp1) {
			if (c == 'a') tmp2 += 'b';
			else tmp2 += 'a';
		}
		return tmp1 == res || tmp2 == res;
	};
	string t1, t2;
	for (int i = 0; i < n; i++) {
		if (i & 1) t1 += 'a', t2 += 'b';
		else t1 += 'b', t2 += 'a';
	}
	bool f = check(t1) || check(t2);
	cout << (f ? "YES" : "NO") << '\n';
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
