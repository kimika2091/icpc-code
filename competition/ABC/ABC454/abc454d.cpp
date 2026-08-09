#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s, t;
	cin >> s >> t;
	// if (s == t) {
	// 	cout << "Yes" << '\n';
	// 	return;
	// }
	// int xs = 0, xt = 0;
	// for (char c : s) xs += c == 'x';
	// for (char c : t) xt += c == 'x';
	// if (xs != xt) {
	// 	cout << "No" << '\n';
	// 	return;
	// }
	stack <char> stk;
	string S = "" , T = "";
	for (char c : s) {
		if (c == ')') {
			if (stk.size() >= 3) {
				char c1 = stk.top(); stk.pop();
				char c2 = stk.top(); stk.pop();
				char c3 = stk.top(); stk.pop();
				if (c1 == 'x' && c2 == 'x' && c3 == '(') {
					stk.push(c1);
					stk.push(c2);
					continue;
				} 
				stk.push(c3);
				stk.push(c2);
				stk.push(c1);
			}
		}
		stk.push(c);
	}
	while (!stk.empty()) S += stk.top(), stk.pop();
	for (char c : t) {
		if (c == ')') {
			if (stk.size() >= 3) {
				char c1 = stk.top(); stk.pop();
				char c2 = stk.top(); stk.pop();
				char c3 = stk.top(); stk.pop();
				if (c1 == 'x' && c2 == 'x' && c3 == '(') {
					stk.push(c1);
					stk.push(c2);
					continue;
				} 
				stk.push(c3);
				stk.push(c2);
				stk.push(c1);
			}
		}
		stk.push(c);
	}
	while (!stk.empty()) T += stk.top(), stk.pop();
	// cout << S << ' ' << T << '\n'; 
	cout << (S == T ? "Yes" : "No") << '\n';
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
