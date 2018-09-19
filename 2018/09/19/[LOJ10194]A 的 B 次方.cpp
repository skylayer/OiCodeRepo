#include<bits/stdc++.h>
using namespace std;

int a,b,m;
int main()
{
    scanf("%d%d%d",&a,&b,&m);
    int ans=1;

    while(b)
        {
            if(b&1) ans=(long long)ans*a%m;

            a=(long long)a*a%m;
            b>>=1;
        }

    printf("%d",ans);



    return 0;
}
