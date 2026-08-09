#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	auto check = [&](char c) -> void {
		if ('a' <= c && c <= 'c') cout << 2;
		if ('d' <= c && c <= 'f') cout << 3;
		if ('g' <= c && c <= 'i') cout << 4;
		if ('j' <= c && c <= 'l') cout << 5;
		if ('m' <= c && c <= 'o') cout << 6;
		if ('p' <= c && c <= 's') cout << 7;
		if ('t' <= c && c <= 'v') cout << 8;	
		if ('w' <= c && c <= 'z') cout << 9;	
	};
	for (int i = 1; i <= n; i++) {
		cin >> s;
		check(s[0]);
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