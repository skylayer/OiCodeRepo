#include<bits/stdc++.h>
using namespace std;

const long long inf=0x3f3f3f3f3f3f3f3f;

int n,m,k,s;
int p,q;

struct line {
	int v;long long w;int next;
}e[200000+10<<1];
int cnt,head[200000+10];
void link(int u,int v,long long w) {
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
long long dis[100000+10];
bool vis[100000+10];
void spfa(int st) {
	memset(dis,63,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st]=0;
	queue<int>que;
	que.push(st);
	while(!que.empty()) {
		int u=que.front();que.pop();vis[u]=0;
		for(int i=head[u];i;i=e[i].next) {
			int v=e[i].v;
			if(dis[u]+e[i].w<dis[v]) {
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]) que.push(v),vis[v]=1;
			}
		}
	}
	
	
}

bool fucked[100000+10];
bool dg[100000+10];


int main() {
	scanf("%d%d%d%d%d%d",&n,&m,&k,&s,&p,&q);
	for(int i=1;i<=k;i++) {
		int v;
		scanf("%d",&v);
		fucked[v]=1;
	}
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		if(fucked[u]&&fucked[v]);
		else if(fucked[u]) link(0,v,1);
		else if(fucked[v]) link(0,u,1);
		else link(u,v,1),link(v,u,1);
	}
	spfa(0);
	for(int i=1;i<=n;i++)
		if(dis[i]<=s)
			dg[i]=1;
	
	for(int i=1;i<=cnt;i++) {
		if(dg[e[i].v]) e[i].w=q;
		else if(fucked[e[i].v]) e[i].w=inf;
		else e[i].w=p;
		if(e[i].v==n||e[i].v==1) e[i].w=0;
	}
	
	spfa(1);
	
	cout<<dis[n];
	
	return 0;
}
