#include<bits/stdc++.h>
using namespace std;
long long dx[401][401],dn[401][401],frt[401],a[401];
int n;



int main() {
    memset(dn,0x3f,sizeof dn);
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        scanf("%lld",&frt[i]);
        dn[i][i]=0;
//		dn[i+n][i+n]=dx[i+n][i+n]=dn[i][i]=dx[i][i];
        frt[i+n]=frt[i];
        frt[i]+=frt[i-1];
//		printf("frt[%d]=%d\n",i,frt[i]);
    }

    for(int i=1; i<=n; i++) frt[i+n]+=frt[i+n-1],dn[i+n][i+n]=0;

    for(int len=2; len<=n; len++) {
        for(int l=1,r=len; r<=2*n; l++,r++) {
            for(int k=l; k<r; k++) {
                dx[l][r]=max(dx[l][r],dx[l][k]+dx[k+1][r]+frt[r]-frt[l-1]);
                dn[l][r]=min(dn[l][r],dn[l][k]+dn[k+1][r]+frt[r]-frt[l-1]);
            }
        }
    }

    long long ans=dn[0][0];

    for(int i=1; i<=n; i++)
        ans=min(ans,dn[i][i+n-1]);

    printf("%lld\n",ans);
    ans=0;

    for(int i=1; i<=n; i++)
        ans=max(ans,dx[i][i+n-1]);

    printf("%lld",ans);




    return 0;
}
