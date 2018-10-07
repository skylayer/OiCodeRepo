#include<bits/stdc++.h>
using namespace std;
int m,n;

struct line {
    int v,w,next;
} e[1001];
int head[1001],cnt;
void link(int u,int v,int w) {
    e[++cnt]= {v,w,head[u]};
    head[u]=cnt;
}

int f[1001][1001];

void dfs(int u) {
    for(int t=head[u]; t; t=e[t].next) {
        int v=e[t].v;
        dfs(v);

        for(int i=n; i>0; i--) {
            for(int j=i; j>0; j--) {
                f[u][i]=max(f[u][i],f[v][j-1]+f[u][i-j]+e[t].w);
            }
        }
    }
}

int main() {
    scanf("%d%d",&m,&n);

    for(int i=1; i<=m; i++) {
        int pre,w;
        scanf("%d%d",&pre,&w);
        link(pre,i,w);
    }

    dfs(0);

    cout<<f[0][n];

    return 0;
}
