#include<bits/stdc++.h>
using namespace std;
int n,dp[201][201],num[201];



int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]),num[i+n]=num[i];

    for(int len=2; len<=n; len++) {
        for(int l=1,r=len; r<2*n; r++,l++) {
            for(int k=l; k<r; k++) {
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]+num[l]*num[k+1]*num[r+1]);
            }
        }
    }

    int ans=0;

    for(int i=1; i<=n; i++) ans=max(ans,dp[i][i+n-1]);

    printf("%d",ans);


    return 0;
}
