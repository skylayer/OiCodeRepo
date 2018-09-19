#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int h[(int)1e6+10];
int row[1001][1001], column[1001][1001];
int ans[1001][1001];

struct cmp
{
    inline bool operator()(int a,int b) const
    {
        return h[a] > h[b];
    }
};


int getans(int x,int y)
{
    register int ans=0;
    register set<int>chk;

    for(int i=1; i<=m; i++)
        chk.insert(column[i][x]);

    for(int i=1; i<=n; i++)
        {
            set<int>::iterator p=chk.lower_bound(row[i][y]);

            if(p!=chk.end()&&*p==row[i][y]) ans++;
        }

    return ans;
}

int main()
{
    freopen("ex_A3.in","r",stdin);
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= m ; j ++)
                {
                    int pos = i * (m + n) + j;
                    scanf("%d", &h[pos]);
                    row[i][j] = pos;
//			printf("row[%d][%d]=%d\n",i,j,row[i][j]);
                    column[j][i] = pos;
//			printf("column[%d][%d]=%d\n",j,i,column[j][i]);
                }
        }

    for(int i = 1 ; i <= n ; i ++)
        sort(row[i]+1,row[i]+m+1,cmp());

    for(int j = 1 ; j <= m ; j ++)
        sort(column[j]+1,column[j]+n+1,cmp());


    for(int i = 1 ; i <= q ; i ++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",getans(y,x));
        }

    return 0;
}
