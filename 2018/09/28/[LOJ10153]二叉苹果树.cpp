#include<bits/stdc++.h>
using namespace std;
int n,q;

struct line {
    int v,w,next;
} e[201];
int head[101],cnt;
void link(int u,int v,int w) {
    e[++cnt]= {v,w,head[u]};
    head[u]=cnt;
}

int f[101][101];

void dfs(int u,int fa) {
    for(int _=head[u]; _; _=e[_].next) {
        int v=e[_].v;

        if(v==fa) continue;

        dfs(v,u);

        for(int i=q; i>0; i--) {
            for(int j=i; j>0; j--) {
                f[u][i]=max(f[u][i],f[v][j-1]+f[u][i-j]+e[_].w);
            }
        }
    }
}


int main() {
    scanf("%d%d",&n,&q);

    for(int i=1; i<n; i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        link(u,v,w);
        link(v,u,w);
    }

    dfs(1,0);

    cout<<f[1][q];


    return 0;
}
