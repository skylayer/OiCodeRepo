#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;

char src[51][51],msk[51][51];

//queue<int>lst;
//
//int c[N][26],len[N],fail[N],cnt;
//void insert(string s) {
//	int l=s.length();int now=0;
//	for(int i=0;i<l;i++) {
//		int v=s[i]='a';
//		if(!c[now][v]) c[now][v]=++cnt;
//		now=c[now][v];
//	}
//	val[now]=l;
//}
//
//void build() {
//	for(int i=0;i<26;i++)
//		if(c[0][i]) fail[c[0][i]]=0,lst.push(c[0][i]);
//	while(!lst.empty()) {
//		int u=lst.front();lst.pop();
//		for(int i=0;i<26;i++) {
//			if(c[u][i]) fail[c[u][i]]=c[fail[u]][i],lst.push(c[u][i]);
//			else c[u][i]=c[fail[u]][i];
//		}
//	}
//}
//
//int query(string s) {
//	int l=s.length();
//	int now=0,ans=0;
//	for(int i=0;i<len;i++) {
//		now=c[now][s[i]-'a'];
//		for(int t=now;t&&(~val[t]))
//	}
//}

set<string>lst;

void T() {
    char tmp[51][51];
    memcpy(tmp,msk,sizeof tmp);
    memset(msk,'.',sizeof msk);

    for(register int i=1; i<=n; i++)
        for(register int j=1; j<=n; j++)
            if(tmp[i][j]^'.')
                msk[j][n-i+1]='*';
}

string get() {
    string ans;

    for(register int i=1; i<=n; i++)
        for(register int j=1; j<=n; j++)
            if(msk[i][j]^'.')
                if(src[i][j]^'.')
                    ans+=src[i][j];

    return ans;
}


void work() {
    lst.clear();
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char c=getchar();

            while(isspace(c)) c=getchar();

            src[i][j]=c;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char c=getchar();

            while(isspace(c)) c=getchar();

            msk[i][j]=c;
        }
    }

    string pcd[5];

    for(int i=1; i<=4; i++) {
        pcd[i]=get();
        T();
    }

    scanf("%d",&m);

    for(int i=1; i<=m; i++) {
        string ans;
        cin>>ans;
        lst.insert(ans);
    }

    queue<string>bff;
    map<string,string>fa;

    while(!bff.empty()) {
        string u=bff.front();
        bff.pop();

        for(set<string>::iterator p=lst.begin(); p!=lst.end(); p++) {
            if(u.substr(0,p->length())==*p) {
                string llll;
                bff.push(llll=u.substr(p->length()));

                if(!llll.length())
                }
        }
    }





}

int main() {
    int T;
    scanf("%d",&T);

    for(int i=1; i<=T; i++) {
        printf("Case #%d: ",i);
        work();
    }



    return 0;
}
