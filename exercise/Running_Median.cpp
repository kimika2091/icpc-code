#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int number, M;
	cin >> number >> M;
	priority_queue <int> max_heap;
	priority_queue <int, vector<int>, greater<int>> min_heap;
	int total = (M + 1) / 2;
	cout << number << ' ' << total << '\n';
	vector <int> ans;
	for (int i = 1; i <= M; i++) {
		int x;
		cin >> x;
		max_heap.push(x);
		if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
			int a = max_heap.top(); max_heap.pop();
			int b = min_heap.top(); min_heap.pop();
			max_heap.push(b);
			min_heap.push(a);
		}
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		} 
		else if (max_heap.size() < min_heap.size()){
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		if (i & 1) {
			ans.push_back(max_heap.top());
		}
	}
	for (int i = 0; i < total; i++) {
		cout << ans[i] << " \n"[(i + 1) % 10 == 0 || i == total - 1];
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