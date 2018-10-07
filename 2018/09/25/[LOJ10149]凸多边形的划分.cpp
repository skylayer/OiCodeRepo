#include<bits/stdc++.h>
using namespace std;

__int128 n,dp[101][101],num[101];




int main() {
    memset(dp,63,sizeof dp);
    cin>>n;

    for(int i=1; i<=n; i++)
        scanf("%lld",&num[i]),num[i+n]=num[i];

    dp[1][3]=num[1]*num[2]*num[3];

    for(int l=2,r=4; r<=2*n; l++,r++) dp[l][r]=dp[l-1][r-1]/num[l-1]*num[r];

    for(int len=4; len<=n; len++) {
        for(int l=1,r=len; r<=2*n; l++,r++) {
            dp[l][r]=min(dp[l][r],min(dp[l][r-1]+num[r]*num[l]*num[r-1],dp[l+1][r]+num[r]*num[l+1]*num[l]));
        }
    }

    long long ans=dp[0][0];

    for(int i=1; i<=n; i++)
        ans=min(ans,dp[i][i+n-1]);

    cout<<ans;
    return 0;
}
