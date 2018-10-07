#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[11][11];

inline int fac(int x) {
    int ans=1;

    for(int i=2; i<=x; i++) ans*=i;

    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    f[0][0]=1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            f[i][j]=j*f[i-1][j]+f[i-1][j-1];

    int ans=f[n][m]*fac(m);
    printf("%d",ans);


    return 0;
}
