#include<bits/stdc++.h>
using namespace std;

int k,p;

int inv[3000010];


int main()
{
    scanf("%d%d",&k,&p);
    printf("1\n");
    inv[1]=1;

    for(int i=2; i<=k; i++)
        {
            inv[i]=(long long)(p-p/i)*inv[p%i]%p;
            printf("%d\n",inv[i]);
        }



    return 0;
}
