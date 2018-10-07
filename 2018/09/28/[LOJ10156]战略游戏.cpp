#include<bits/stdc++.h>
using namespace std;

struct line {
    int to,next;
} e[20000];
int head[10001],cnt;
inline void link(int u,int v) {
    e[++cnt]= {v,head[u]};
    head[u]=cnt;
}

int f[2][1501];

int dfs(const int&now,const int&fa) {
    f[1][now]=1;

    for(int i=head[now]; i; i=e[i].next) {
        int v=e[i].to;

        if(v^fa) {
            dfs(v,now);
            f[0][now]+=f[1][v];
            f[1][now]+=min(f[0][v],f[1][v]);
        }
    }
}
int n;

int ent;
int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        int id,k;
        scanf("%d%d",&id,&k);

        if(!ent) ent=id;

        for(int j=1; j<=k; j++) {
            int v;
            scanf("%d",&v);
            link(id,v),link(v,id);
        }
    }

    dfs(ent,-1);
    printf("%d",min(f[0][ent],f[1][ent]));


    return 0;
}
