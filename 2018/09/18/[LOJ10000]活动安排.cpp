#include<bits/stdc++.h>
using namespace std;

int n;
struct act
{
    int l,r;
    inline bool operator<(act x) const
    {
        if(l<x.l) return true;

        if(l>x.l) return false;

        return r<x.r;
    }
} e[1001];

int dp[1001];

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d%d",&e[i].l,&e[i].r);

    sort(e+1,e+1+n);

    for(int i=1; i<=n; i++)
        {
            for(int j=0; j<i; j++)
                {
                    if(e[j].r<=e[i].l)
                        {
                            dp[i]=max(dp[i],dp[j]+1);
                        }
                }
        }

    printf("%d",dp[n]);

    return 0;
}
