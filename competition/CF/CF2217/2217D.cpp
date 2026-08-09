#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> p(k + 1);
    for (int i = 1; i <= k; i++) cin >> p[i];

    int x = a[p[1]]; // 基准值
    
    // 构造目标数组 b (与 x 不同则为 1，相同则为 0)
    vector<int> b(n + 2, 0); 
    for (int i = 1; i <= n; i++) b[i] = a[i] ^ x;

    // 使用你熟悉的定义：c[i] = b[i] ^ b[i-1]
    // 差分数组范围是 1 到 n+1
    vector<int> c(n + 2, 0);
    int M = 0;
    for (int i = 1; i <= n + 1; i++) {
        c[i] = b[i] ^ b[i - 1];
        if (c[i] == 1) M++;
    }

    int S_max = 0;
    int current_block_count = 0;
    int p_idx = 1;

    for (int i = 1; i <= n + 1; i++) {
        if (c[i] == 1) current_block_count++;
        
        // 当 i 达到特殊点 p[p_idx] 时，当前区块结束
        // 注意：在你定义的 [l, r+1] 模型中，p 是包含在区块末尾的
        if (p_idx <= k && i == p[p_idx]) {
            S_max = max(S_max, current_block_count);
            current_block_count = 0;
            p_idx++;
        }
    }
    S_max = max(S_max, current_block_count); // 结算最后一个区块 (p_k 之后到 n+1)

    cout << max(M / 2, S_max) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}