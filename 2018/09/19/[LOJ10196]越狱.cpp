#include<bits/stdc++.h>
using namespace std;
const int mod=100003;



int fpow(long long base,long long index) {
    int ans=1;

    while(index) {
        if(index&1) ans=(long long)ans*base%mod;

        base=(long long)base*base%mod;
        index>>=1;
    }

    return ans;
}


long long m,n;

int main() {
    scanf("%lld%lld",&m,&n);

    int ans=fpow(m,n)-(long long)m*fpow(m-1,n-1)%mod;

    if(ans<0) ans+=mod;

    printf("%d",ans);




    return 0;
}
