#include <iostream>
#include <stdio.h>
#include <cstring>
#define RG register
using namespace std;
const int N = 50010;
const int mod = 1e9 + 7;
int n, q;
long long A[N], B[N], C[N];
long long ans = 1;
long long Pow(long long x, long long y) {
    long long ans = 1ll;

    for(; y ; y >>= 1, x = x * x % mod) if(y & 1) ans  = ans * x % mod;

    return ans;
}
int main() {
    scanf("%d%d", &n, &q);

    for(RG int i = 1; i <= n; ++i)
        scanf("%lld", &A[i]);

    for(RG int i = 1; i <= n; ++i)
        scanf("%lld", &B[i]);

    for(RG int i = 1; i <= n; ++i)
        C[i] = max(C[i - 1], A[i]);

    for(RG int i = 1; i <= n; ++i)
        ans = ans * min(B[i], C[i]) % mod;

    for(RG int i = 1; i <= q; ++i) {
        int op, x;
        long long y;
        scanf("%d%d%lld", &op, &x, &y);

        if(op == 0) {
            A[x] = y;
            ans = ans * Pow(min(B[x], C[x]), mod - 2) % mod;

            for(RG int j = x; j <= n; ++j)
                C[i] = max(C[i - 1], A[i]);

            ans = ans * min(B[x], C[x]) % mod;
            printf("%lld\n", ans);
        }

        if(op == 1) {
            ans = ans * Pow(min(B[x], C[x]), mod - 2) % mod;
            B[x] = y;
            ans = ans * min(B[x], C[x]) % mod;
            printf("%lld\n", ans);
        }
    }

    return 0;
}

