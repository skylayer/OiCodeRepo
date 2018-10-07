#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int fa[200005];
inline int f(int x) {
    while(fa[x]^x) x=fa[x]=fa[fa[x]];

    return x;
}
int main() {
    scanf("%d%d",&n,&m);

    for(int i=0; i<=n+1; ++i) fa[i]=i;

    while(m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        b=f(b);

        while(a<=b) {
            if(a!=b && f(a)==b)break;

            fa[b]=f(b-1);
            cnt++;
            b=f(b);
        }

        printf("%d\n",n-cnt);
    }
}
