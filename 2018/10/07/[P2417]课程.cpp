#include<bits/stdc++.h>
using namespace std;

int pr[20000+10];
vector<int>student[3000];
int vis[3000],p,n;

bool dfs(int u) {
//	printf("dfs%d\n",u);
    vis[u]=1;

    for(int i=0; i<student[u].size(); i++) {
        if(vis[pr[student[u][i]]]) continue;

        if((!pr[student[u][i]])||dfs(pr[student[u][i]])) {
            pr[student[u][i]]=u;
            return true;
        }
    }

    return false;
}


void work() {
    memset(pr,0,sizeof pr);
    scanf("%d%d",&p,&n);

    for(int i=1; i<=p; i++) {
        int num;
        scanf("%d",&num);
        student[i].clear();

        for(int j=1; j<=num; j++) {
            int nas;
            scanf("%d",&nas);
            student[i].push_back(nas);
        }
    }

    for(int i=1; i<=p; i++) {
        memset(vis,0,sizeof vis);

        if(!dfs(i)) {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");


}

int main() {

    int T;
    scanf("%d",&T);

    while(T--) work();


    return 0;
}
