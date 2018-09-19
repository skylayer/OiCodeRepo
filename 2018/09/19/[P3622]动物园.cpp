#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int n,m;
int num[maxn][40],f[maxn][40];


int ans;
int main() {
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++) {
        int a,b,c,l,d,t;
        scanf("%d%d%d",&a,&b,&c);
        l=d=0;

        for(int j=1; j<=b; j++) {
            scanf("%d",&t);
            t=(t-a+n)%n;
            l|=1<<t;
        }

        for(int j=1; j<=c; j++) {
            scanf("%d",&t);
            t=(t-a+n)%n;
            d|=1<<t;
        }

        for(int i=0; i<32; i++) {
            if((i&l)||(~i&d)) {
                num[a][i]++;
            }
        }
    }

    for(int i=0; i<32; i++) {
        memset(f,128,sizeof f);
        f[0][i]=0;

        for(int j=1; j<=n; j++) {
            for(int s=0; s<32; s++) {
                f[j][s]=max(f[j-1][(s&15)<<1],f[j-1][(s&15)<<1|1])+num[j][s];
            }

            if(ans<f[n][i]) ans=f[n][i];
        }
    }

    printf("%d",ans);


    return 0;
}
