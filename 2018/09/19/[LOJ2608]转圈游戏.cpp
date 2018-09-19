#include<bits/stdc++.h>
using namespace std;


int n,m,k,x;

int main() {
    scanf("%d%d%d%d",&n,&m,&k,&x);
    int base=10;

    while(k) {
        if(k&1) m=(long long)m*base%n;

        k>>=1;
        base=(long long)base*base%n;
    }

    printf("%d",((long long)x+m)%n);



    return 0;
}
