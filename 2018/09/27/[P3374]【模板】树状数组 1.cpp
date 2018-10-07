#include<bits/stdc++.h>
using namespace std;

int n,m,bit[500001];
#define lowbit(x) (-x&x)
void add(int x,int k) {
    for(int i=x; i<=n; i+=lowbit(i))
        bit[i]+=k;
}
int find(int x) {
    int sum=0;

    for(int i=x; i; i-=lowbit(i))
        sum+=bit[i];

    return sum;
}


int main() {
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++) {
        int ans;
        scanf("%d",&ans);
        add(i,ans);
    }

    for(int i=1; i<=m; i++) {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);

        if(t==1) {
            add(x,y);
        } else printf("%d\n",find(y)-find(x-1));
    }

    return 0;
}
