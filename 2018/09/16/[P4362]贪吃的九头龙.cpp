#include<bits/stdc++.h>
using namespace std;
const int maxn=310;

int n,m,k;

struct line
{
    int to,w,next;
} e[maxn*2];
int head[maxn],cnt;
inline void link(int from,int to,int w)
{
    e[++cnt]= {to,w,head[from]};
    head[from]=cnt;
}


int tmp[maxn][2],dp[maxn][maxn][2];
void dfs(int u,int fa)
{
    dp[u][0][0]=dp[u][1][1]=0;

    for(int i=head[u]; i; i=e[i].next)
        {
            int v=e[i].to;

            if(v^fa)
                {
                    dfs(v,u);
                    memcpy(tmp,dp[u],sizeof tmp);
                    memset(dp[u],0x3f,sizeof tmp);

                    for(int j=0; j<=k; j++)
                        {
                            for(int t=0; t<=j; t++)
                                {
                                    dp[u][j][0]=min(dp[u][j][0],min(dp[v][t][0]+tmp[j-t][0]+(m==2)*e[i].w,dp[v][t][1]+tmp[j-t][0]));
                                    dp[u][j][1]=min(dp[u][j][1],min(dp[v][t][1]+tmp[j-t][1]+e[i].w,dp[v][t][0]+tmp[j-t][1]));
                                }
                        }
                }
        }
}




int main()
{
    scanf("%d%d%d",&n,&m,&k);

    if(n-k<m-1)
        {
            printf("-1");
            return 0;
        }

    for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            link(u,v,w);
            link(v,u,w);
        }

    memset(dp,63,sizeof dp);
    dfs(1,0);
    printf("%d",dp[1][k][1]);

    return 0;
}
