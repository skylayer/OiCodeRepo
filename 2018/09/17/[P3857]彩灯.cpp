#include<bits/stdc++.h>
using namespace std;
const int mlog=63;
typedef long long ll;
int cunt;
ll lbs[64];
void insert(ll x)
{
    for(int i=mlog; i>=0; i--)
        {
            if(x&(1ll<<i))
                {
                    if(!lbs[i])
                        {
                            lbs[i]=x;
                            cunt++;
                            return;
                        }
                    else x^=lbs[i];
                }
        }
}
int n,m;


int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++)
        {
            long long ans=0;

            for(int j=1; j<=n; j++)
                {
                    char c=getchar();

                    while(isspace(c)) c=getchar();

                    ans<<=1;

                    if(c^'X') ans|=1;
                }

            insert(ans);
        }

    printf("%d",(1ll<<cunt)%2008);



    return 0;
}
