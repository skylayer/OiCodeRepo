#include<bits/stdc++.h>
using namespace std;
long long base[64],mlg=60,ans;
void insert(long long x) {
    for(int i=mlg; x&&i>=0; i--) {
        if(x&(1ll<<i)) {
            if(!base[i]) {
                base[i]=x;
                break;
            }

            x^=base[i];
        }
    }
}
int n;
int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        long long p;
        scanf("%lld",&p);
        insert(p);
    }

    for(int i=60; i>=0; i--) {
        ans=max(ans,ans^base[i]);
    }

    printf("%lld",ans);


    return 0;
}
