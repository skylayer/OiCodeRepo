#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ul;
unsigned int st,tg;

inline ul opt1(ul x) {
    ul ans=0;
    ans=0xFFFF&x;
    x>>=0x10;
    ans<<=0x10;
    return ans|x;
}

inline ul opt2(ul x) {
    ul ans=0;
    ul tans=0;
    tans=x&(ul)0xF000F;
    ans=x&(ul)0xFFF0FFF0;
    ans>>=4;
    tans<<=12;
    return ans|tans;
}

inline ul opt3(ul x) {
    ul stc=x&(ul)0xF00FF00F;
    int aans=(ul)0xF000000&x;
    aans>>=4;
    stc|=aans;
    aans=(ul)0xF00000&x;
    aans>>=0x10;
    stc|=aans;
    aans=(ul)0xF0&x;
    aans<<=4;
    stc|=aans;
    aans=(ul)0xF00&x;
    aans<<=0x10;
    stc|=aans;
    return stc;
}

inline ul opt(ul x,int mode) {
    if(mode==1) return opt1(x);
    else if(mode==2) return opt2(x);

    return opt3(x);
}

map<ul,ul>step,fa,opr;

void bfs() {
    queue<ul>lst;
    fa[st]=0;
    lst.push(st);
    step[st]=1;

    while(!lst.empty()) {
        ul u=lst.front();
        lst.pop();

        for(int i=1; i<=3; i++) {
            ul v=opt(u,i);

            if(!step[v]) lst.push(v),step[v]=step[u]+1,fa[v]=u,opr[v]=i;

            if(v==tg) return;
        }
    }
}


int main() {
    st=305432421;

    for(int i=0; i<8; i++) {
        int ans;
        scanf("%d",&ans);
        tg<<=4;
        tg|=ans;
    }

    bfs();
    cout<<step[tg]-1<<endl;
    vector<char>ans;

    for(int i=tg; i!=st; i=fa[i])
        ans.push_back(opr[i]-1+'A');

    for(auto p:ans) cout<<p;

    return 0;
}
