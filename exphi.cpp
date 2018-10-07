#include<bits/stdc++.h>
using namespace std;
long long solve(long long n,long long r) {
    vector<int>p;

    for(int i=2; i*i<=n; ++i) {
        if(n%i==0) {
            p.push_back(i);

            while(n%i==0) n/=i;
        }
    }

    if(n>1) p.push_back(n);

    long long sum=0;

    for(int msk=1; msk<(1<<p.size()); ++msk) {
        long long mult=1,
                  bits=0;

        for(int i=0; i<(int)p.size(); ++i)
            if(msk&(1<<i)) {
                ++bits;
                mult*=p[i];
            }

        long long cur=r/mult;

        if(bits%2==1) sum+=cur;
        else sum-=cur;
    }

    return r-sum;
}


int main() {
    freopen("phi.in","r",stdin);
    freopen("phi.out","w",stdout);
    long long n,r;
    scanf("%d%d",&n,&r);

    for(int i=1; i<=n; i++) {
        printf("%lld\n",solve(i,r));
    }




    return 0;
}

