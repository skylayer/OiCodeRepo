#include<bits/stdc++.h>
using namespace std;
const int full=341;
int n,k;
int dp[11][2050][101];



int gnum(int x) {
    int ans=0;

    for(int i=0; (1<<i)<=x; i++)
        if(x&(1<<i))
            ans++;

    return ans;
}

int gsub(int i) {
    int V=(1<<n)-1;

    for(int j=9; j>=0; j--)
        if(1<<j&i)
            V&=(1<<n)-1^(1<<j)^(1<<j-1)^(1<<j+1);

    return V;
}

int main() {
    scanf("%d%d",&n,&k);

    for(int i=1; i<=(1<<n)-1; i++) dp[0][i][0]=1;

    for(int l=1; l<=n; l++) {
        int S=full&(1<<n)-1;

        for(int i=S; i; i=i-1&S) {
            int num=gnum(i),V=gsub(i);

            for(int j=V; j; j=j-1&V) {
                for(int t=k; t>=num; t--) {
                    dp[l][i][t]+=dp[l-1][j][t-num];
                }
            }
        }

        S=(full<<1)&(1<<n)-1;

        for(int i=S; i; i=i-1&S) {
            int num=gnum(i),V=gsub(i);

            for(int j=V; j; j=j-1&V) {
                for(int t=k; t>=num; t--) {
                    dp[l][i][t]+=dp[l-1][j][t-num];
                    dp[l][2049][t]=max(dp[l][2049][t],dp[l][i][t]);
                }
            }
        }
    }

    cout<<dp[n][2049][k];


    return 0;
}
