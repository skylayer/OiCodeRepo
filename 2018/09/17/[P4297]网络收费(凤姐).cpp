#include<bits/stdc++.h>
using namespace std;
const int N = 1<<11;
int n,B,C[N],sel[N],fangan[N],cnt[N][2],liuliang[N][N];

void wrk()
{
    int maxn = (1<<n)-1,cost = 0,ans=1e9;

    for(int S=0; S<=maxn; S ++)
        {
            cost=0;

            for(int i=1; i<=n; i ++)
                {
                    fangan[i]=(((1<<(i-1))&S)>0);

                    if(sel[i] != fangan[i])cost += C[i];

                    cnt[i+B][fangan[i]]=1;
                    cnt[i+B][fangan[i]^1]=0;
                }

            for(int i=B; i; i --)
                cnt[i][0]=cnt[i<<1][0]+cnt[i<<1|1][0],
                          cnt[i][1]=cnt[i<<1][1]+cnt[i<<1|1][1];

            for(int i=1; i<=n; i ++)
                for(int j=i + 1; j<=n; j ++)
                    {
                        if(fangan[i] != fangan[j])cost += liuliang[i][j];
                        else
                            {
                                int x=i + B,y=j + B;

                                while(x!=y)
                                    x>>=1,y>>=1;

                                cost += (!((fangan[i] == 0)^(cnt[x][0]<cnt[x][1])))*2*liuliang[i][j];
                            }
                    }

            ans=min(ans, cost);
        }

    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&n);
    n=1 << n;
    B=n - 1;

    for(int i=1; i<=n; i ++)scanf("%d",&sel[i]);

    for(int i=1; i<=n; i ++)scanf("%d",&C[i]);

    for(int i=1; i<=n; i ++)
        for(int j=i + 1; j<=n; j ++)
            scanf("%d",&liuliang[i][j]);

    wrk();
    return 0;
}
