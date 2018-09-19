#include<bits/stdc++.h>
using namespace std;

const int maxn=11,maxm=(1<<10)+1,maxp=maxm<<1,inf=0x7fffffff>>1;

struct rec
{
    int r[maxp],lim;
    inline int get(int a,int b)
    {
        int c=a*lim+b;
        return r[c];
    }
    inline void set(int a,int b,int v)
    {
        int c=a*lim+b;
        r[c]=v;
    }
} rcd[maxp];
int n,m,ac,ans,newans;
int anc[maxm][maxn],cost[maxm][maxn],flow[maxm][maxm];
int con[maxm];
bool type[maxm],mark;
void init()
{
    scanf("%d",&n);
    m=1<<n;

    for(int i=1; i<=m; i++)
        {
            int a;
            scanf("%d",&a);
            type[i]=!a;
        }

    for(int i=1; i<=m; i++)
        scanf("%d",&con[i]);

    for(int i=1; i<m; i++)
        {
            for(int j=i+1; j<=m; j++)
                {
                    int a;
                    scanf("%d",&a);
                    flow[i][j]=flow[j][i]=a;
                }
        }

    ans=inf;
}

int brink(int a,int na,int S)
{
    int ca=0,cb=0;

    for(int i=1; i<=n; i++,S>>=1)
        {
            if(S&1) ca+=cost[a][i];
            else cb+=cost[a][i];
        }

    if(na==1) return ca+(type[a]?0:con[a]);
    else return cb+(type[a]?con[a]:0);
}

int dp(int i,int j,int k,int hgt)
{
    int rs=rcd[i].get(j,k);

    if(!rs)
        {
            if(hgt)
                {
                    rs=inf;
                    int newrs,a,ls,tk;
                    mark=j<((1<<hgt)-j);
                    tk=(k<<1)+mark;
                    ls=1<<hgt-1;

                    if((a=j-ls)<0) a=0;

                    for(; a<=j&&a<=ls; a++)
                        {
                            newrs=dp(i<<1,a,tk,hgt-1);
                            newrs+=dp((i<<1)+1,j-a,tk,hgt-1);

                            if(newrs<rs)
                                rs=newrs;
                        }
                }
        }
    else
        {
            rs=brink(i-m+1,j,k);
        }

    rcd[i].set(j,k,rs);
    return rs;
}

void solve()
{
    int newans;

    for(int i=1; i<=n; i++)
        {
            int k=i+m+1;

            for(int j=1; j<=n; j++)
                {
                    k>>=1;
                    anc[i][j]=k;
                }
        }

    for(int k=1; k<=n+1; k++)
        {
            int a=1<<k-1,b=(1<<k)-1;
            int l=n-k+1;

            for(int p=a; p<=b; p++)
                {
                    rcd[p].lim=1<<n-1;
                    memset(rcd[p].r,0,sizeof rcd[p].r);
                }
        }

    for(int i=1; i<=m; i++)
        {
            for(int j=i+1; j<=m; j++)
                {
                    for(int k=1; k<=n; k++)
                        {
                            if(anc[i][k]==anc[j][k])
                                {
                                    cost[i][k]+=flow[i][j];
                                    cost[j][k]+=flow[i][j];
                                    break;
                                }
                        }
                }
        }

    for(int i=0; i<=m; i++)
        {
            newans=dp(1,i,0,n);

            if(newans<ans)
                ans=newans;
        }
}





int main()
{
    init();
    solve();
    printf("%d",ans);
    return 0;
}
