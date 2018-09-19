#include<bits/stdc++.h>
using namespace std;
map<int,int>lev;
int n,m,q;
int num[(int)1e5+10],level[(int)1e5+1000];

int getlev(int x) {
    int ans=m;
    map<int,int>::iterator p=lev.upper_bound(x);

    if(p!=lev.end()) ans=p->second-1;

    return ans;
}

int main() {
    lev[0]=0;
    scanf("%d%d%d",&n,&m,&q);

    for(int i=1; i<=m; i++) {
        int ned;
        scanf("%d",&ned);
        lev[ned]=i;
    }

    for(int i=1; i<=n; i++) {
        scanf("%d",&num[i]);
    }

    for(int i=1; i<=q; i++) {
        int type;
        scanf("%d",&type);

        if(type==1) {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);

            for(int i=l; i<=r; i++) {
                num[i]+=x;
            }
        } else if(type==2) {
            int p,x;
            scanf("%d%d",&p,&x);
            num[p]+=x;
        } else {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=0;

            for(int i=l; i<=r; i++) {
                ans+=getlev(num[i]);
            }

            printf("%d\n",ans);
        }

    }


    return 0;
}
