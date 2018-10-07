#include<bits/stdc++.h>
using namespace std;
int s,n;
set<long long>dp[2];
vector<long long>o;
int cnt;



int main() {
    scanf("%d%d",&s,&n);

    for(int i=1; i<=n; i++) {
        long long w,v;
        scanf("%lld%lld",&w,&v);
        long long ans=pow(w,v);

        if(ans>s) continue;

        o.push_back(ans);
    }

    dp[cnt].insert(0);

    for(int i=0; i<o.size(); i++) {
        dp[cnt^1].clear();

        for(auto p:dp[cnt]) {
            if(p+o[i]>s) continue;

            dp[cnt^1].insert(p+o[i]);
        }

        cnt^=1;
    }

    printf("%lld\n",*dp[cnt].rbegin());


    return 0;
}
