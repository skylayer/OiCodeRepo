#include<bits/stdc++.h>
using namespace std;
int n;
int num[(int)1e5+10];
int cunt[3][(int)1e5+10];

int ntr;

int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]);

    for(int i=1; i<=n; i+=2)
        cunt[1][num[i]]++;

    for(int i=2; i<=n; i+=2)
        cunt[2][num[i]]++;

    sort(cunt[1]+1,cunt[1]+n,greater<int>());




    return 0;
}
