#include<bits/stdc++.h>
using namespace std;
int block[55][55];
int bkw[55][55];
int f[55][55][3310];
int n,m;
int ans;

int main()
{
    scanf("%d%d",&n,&m);
    memset(f,-128,sizeof f);
    f[n+1][0][0]=0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n-i+1; j++)
            scanf("%d",&block[i][j]);

    for(int j=n; j>=1; j--)
        {
            for(int i=0,sum=0; i<=n-j+1; i++,sum+=block[i][j])
                {
                    for(int k=i; k<=m; k++)
                        {
                            for(int l=i-1>0?i-1:0; l<=n-j; l++)
                                {
                                    f[j][i][k]=max(f[j][i][k],f[j+1][l][k-i]+sum);
                                }
                        }
                }
        }

    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n-i+1; j++)
                {
                    ans=max(ans,f[i][j][m]);
                }
        }

    printf("%d",ans);


    return 0;
}
