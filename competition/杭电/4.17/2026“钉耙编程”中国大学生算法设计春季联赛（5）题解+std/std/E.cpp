#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", __builtin_popcount(n ^ 1));
    }
    return 0;
}
