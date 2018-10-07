#include<bits/stdc++.h>
using namespace std;

int n;

struct line {
    int to,next;
} e[(int)1e5];

int head[50001],cnt;
void link(int from,int to) {
//	printf("%d->%d\n",from,to);
    e[++cnt]= {to,head[from]};
    head[from]=cnt;
}

void setup(int x) {
    int ans=1;

    for(int i=2; i*i<=x; i++) { //printf("#x:%d i:%d\n",x,i);
        if(x%i) continue;

        if(i*i^x) ans+=i+x/i;
        else ans+=i;
    }

//	printf("ans:%d\n",ans);
    if(ans>=x) return;

    link(ans,x),link(x,ans);
}

int dis[50001];
int maxx,pos;
void dfs(int u,int fa) {
    dis[u]=dis[fa]+1;

    if(dis[u]>maxx) maxx=dis[u],pos=u;

    for(int i=head[u]; i; i=e[i].next) {
        if(e[i].to^fa) {
            dfs(e[i].to,u);
        }
    }
}


int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        setup(i);

//	memset(dis,63,sizeof dis);
//	dis[0]=1;
    dfs(1,0);
    memset(dis,0,sizeof dis);
    maxx=0;
    dfs(pos,0);
    cout<<maxx-1;


    return 0;
}
