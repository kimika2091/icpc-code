#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int a = 0, ab = 0, abc = 0;
	for (char c : s) {
		int i = c - 'A';
		if (i == 0) {
			a++;
		}
		else if (i == 1){
			if(a) {
				a--;
				ab++;
			}
		}
		else {
			if(ab) {
				ab--;
				abc++;
			}
		}
	}
	cout << abc << '\n';
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
