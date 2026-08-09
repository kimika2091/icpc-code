#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char used[15][4];

struct Card {
	int point, color;
	bool operator < (const Card &others) const {
		return point > others.point;
	}
	void init(const string &s) {
		switch (s[0]) {
			case 'A': point = 14; break;
			case 'J': point = 11; break;
			case 'Q': point = 12; break;
			case 'K': point = 13; break;
			case 'T': point = 10; break;
			default: point = s[0] - '0'; break;
		}
		switch (s[1]) {
			case 'C': color = 0; break;
			case 'D': color = 1; break;
			case 'H': color = 2; break;
			case 'S': color = 3; break;
		}
		used[point][color] = 1;
	}
};

bool Is_straight(vector <Card> x) {
	if (x[0].point == 14 && x[1].point == 5 && x[2].point == 4 && x[3].point == 3 && x[4].point == 2) return true;
	for (int i = 0; i < 4; i++) {
		if (x[i].point - x[i + 1].point != 1) return false;
	}
	return true;
}

bool Is_flush(vector <Card> x) {
	for (int i = 0; i < 4; i++) {
		if (x[i].color != x[i + 1].color) return false;
	}
	return true;
}

pair<int, vector<int>> type (vector <Card> x) {
	vector <int> ret, cnt(15);
	sort(x.begin(), x.end());
	for (int i = 0; i < 5; i++) cnt[x[i].point]++;
	vector <pair<int, int>> S;
	for (int i = 0; i < 4; i++) {
		if (x[i].point == x[i + 1].point) continue;
		S.emplace_back(cnt[x[i].point], x[i].point);
	}
	S.emplace_back(cnt[x[4].point], x[4].point);
	sort(S.begin(), S.end(), [](const pair<int, int> &x, const pair<int, int> &y){
		return x.first != y.first ? x.first > y.first : x.second > y.second;
	});
	for (auto &[i, j] : S) {
		for (int k = 1; k <= i; k++) ret.push_back(j);
	}
	int M = 1;
	if (S[0].first == 2) {
		if (S.size() == 4) M = 2;
		else M = 3;
	}
	if (S[0].first == 3) {
		if (S.size() == 3) M = 4;
		else M = 7;
	}
	if (S[0].first == 4) M = 8;
	bool f1 = Is_straight(x), f2 = Is_flush(x);
	if (f1) {
		if (f2) {
			if (x[0].point == 14 && x[1].point == 13) M = 10;
			else M = 9;
		}
		else {
			M = max(M, 5);
		}
		if (x[0].point == 14 && x[1].point == 5) {
			ret = {5, 4, 3, 2, 1};
		}
	}
	else if (f2) {
		M = max(M, 6);
	}
	return {M, ret};
}

int compare (const pair<int, vector<int>> &x, const pair<int, vector<int>> &y) {
	if (x.first > y.first) return 1;
	if (x.first < y.first) return -1;
	for (int i = 0; i < 5; i++) {
		if (x.second[i] > y.second[i]) return 1;
		if (x.second[i] < y.second[i]) return -1;
	}
	return 0;
}

void solve() {
	for (int i = 2; i <= 14; i++) {
		for (int j = 0; j < 4; j++) {
			used[i][j] = 0;
		}
	}
	string s;
	vector <Card> me(5), god(5);
	for (int i = 0; i < 4; i++) cin >> s, me[i].init(s);
	for (int i = 0; i < 4; i++) cin >> s, god[i].init(s);
	pair<int, vector<int>> m1 = {-1, vector<int>(5)}, m2 = {-1, vector<int>(5)}, g1 = {-1, vector<int>(5)};
	int p1 = 0, c1 = 0, p = 0, c = 0;
	for (int i = 2; i <= 14; i++) {
		for (int j = 0; j < 4; j++) {
			if (used[i][j] == 1) continue;
			me[4].point = i, me[4].color = j;
			auto cur = type(me);
			if (compare(cur, m1) == 1) {
				p1 = i, c1 = j;
				m2 = m1;
				m1 = cur;
			}
			else if (compare(cur, m2) == 1) {
				m2 = cur;
			}
			god[4].point = i, god[4].color = j;
			cur = type(god);
			if (compare(cur, g1) == 1) {
				p = i, c = j;
				g1 = cur;
			}
		}
	}
 	if (p1 == p && c1 == c) {
		int f = compare(m2, g1);
		if (f == 1) cout << "WoYaoYanPai" << '\n';
		else if (f == 0) cout << "PaiMeiYouWenTi" << '\n';
		else cout << "GeiWoCaPiXie" << '\n';
	}
	else {
		int f = compare(m1, g1);
		god[4].point = p1, god[4].color = c1;
		f = min(f, compare(m2, type(god)));
		if (f == 1) cout << "WoYaoYanPai" << '\n';
		else if (f == 0) cout << "PaiMeiYouWenTi" << '\n';
		else cout << "GeiWoCaPiXie" << '\n';		
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0; 
}