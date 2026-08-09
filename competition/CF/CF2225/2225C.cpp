#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector <int> f(n + 1), v1(n + 1), v2(n + 1);
	if (s1[0] != s2[0]) f[0] = 1;
	else v1[0] = v2[0] = 1;
	for (int i = 1; i < n; i++) {
		if (s1[i] == s2[i]) f[i] = f[i - 1], v1[i] = v2[i] = 1;
		else {
			if (s1[i - 1] == s2[i - 1]) f[i] = f[i - 1] + 1;
			else {
				if (s1[i - 1] != s1[i]) f[i] = f[i - 1] + 1;
				else {
					if (!v1[i - 1] && !v2[i - 1]) f[i] = i == 1? 0 : f[i - 2], v1[i] = v2[i] = 1;
					else f[i] = f[i - 1] + 1;
				}
			}
		}
	}
	cout << f[n - 1] << '\n';
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
