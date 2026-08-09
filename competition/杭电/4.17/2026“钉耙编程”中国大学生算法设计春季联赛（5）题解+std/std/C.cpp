#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, t, S;
        scanf("%lld%lld%lld", &n, &t, &S);
        long long maxS = n * ((1LL << t) - 1);
        puts(S <= maxS ? "Yes" : "No");
    }
    return 0;
}
