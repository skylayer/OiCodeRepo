#include<bits/stdc++.h>
using namespace std;

int n,m,bit[500001];
#define lowbit(x) (-x&x)
void _add(int x,int k) {
    for(int i=x; i<=n; i+=lowbit(i))
        bit[i]+=k;
}
void change(int x,int y,int k) {
    _add(x,k);
    _add(y+1,-k);
}
int find(int x) {
//	printf("ASHDKJA");
    int sum=0;

    for(int i=x; i; i-=lowbit(i)) {
        sum+=bit[i];
//		cout<<i;
    }

    return sum;
}


int main() {
    scanf("%d%d",&n,&m);
    int las=0;

    for(int i=1; i<=n; i++) {
        int ans;
        scanf("%d",&ans);
        _add(i,ans-las);
        las=ans;
    }

    for(int i=1; i<=m; i++) {
        int t,x,y,k;
        scanf("%d",&t);

        if(t==1) {
            scanf("%d%d%d",&x,&y,&k);
            change(x,y,k);
        } else {
            scanf("%d",&x);
            printf("%d\n",find(x));
        }
    }

    return 0;
}
