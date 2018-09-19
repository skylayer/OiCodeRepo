#include<bits/stdc++.h>
using namespace std;
int a[8];
long double ans=1,sum;

int main()
{

    for(int i=1; i<=7; i++)
        ans*=i,scanf("%d",&a[i]),sum+=a[i];

    for(int i=1; i<=6; i++)
        ans*=a[i]/(sum-i+1);

    ans*=a[7];

    printf("%.3Lf",ans);


    return 0;
}
