#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
ll _pow(ll x, int n) {
    ll ans = 1;

    for ( ; n; n >>= 1, x = x * x % P)
        if( n&1) ans = ans * x % P;

    return ans;
}
ll n, m;
int main() {
    freopen("zackzh.in", "r", stdin);
    freopen("zackzh.out", "w", stdout);
    scanf("%lld%lld", &n, &m);

    if( n < m) swap(n, m);

    ll L = 1;
    n %= P;

    for ( int i = 1; i <= m; ++ i) L = L * i % P;

    L = _pow(L, P-2);

    for ( int i = n+2; i <= n+m+1; ++ i) L = L * i % P;

    printf("%lld\n", (n + L) % P);
    return 0;
}
