#include<bits/stdc++.h>
using namespace std;

#define abs(a) (a<0?-a:a)

int n,k,ans;

struct robot {
	int x,r,s;
}bot[(int)1e5+10];

struct cmp {
	bool operator()(robot a,robot b) const {
		return a.x<b.x;
	}
};

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&bot[i].x,&bot[i].r,&bot[i].s);
	
	sort(bot+1,bot+n+1,cmp());
	
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(bot[j].x>bot[i].x+bot[i].r) break;
			if(abs(bot[i].s-bot[j].s)>k) continue;
			if(bot[j].x-bot[j].r>bot[i].x) continue;
			ans++;
		}
	}
	
	printf("%d",ans);
	
	
	return 0;
}
