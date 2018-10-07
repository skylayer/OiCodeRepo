#include<bits/stdc++.h>
using namespace std;
char mapp[2001][2001];
int l,q;



inline int row(int x,int y) {
    int u=y,d=y,ans=1;

    while(mapp[x][u-1]&&mapp[x][u-1]==mapp[x][d+1]) u--,d++,ans+=2;

    return ans;
}

inline int column(int x,int y) {
    int u=x,d=x,ans=1;

    while(mapp[u-1][y]&&mapp[u-1][y]==mapp[d+1][y]) u--,d++,ans+=2;

    return ans;
}

inline int query(int x,int y) {
    return max(row(x,y),column(x,y));
}

int main() {
    scanf("%d%d",&l,&q);

    for(int i=1; i<=l; i++)
        scanf("%s",mapp[i]+1);

    for(int i=1; i<=q; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }



    return 0;
}
