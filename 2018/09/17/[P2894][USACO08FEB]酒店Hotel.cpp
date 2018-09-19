#include<bits/stdc++.h>
using namespace std;

#define max(a,b) (a>b?a:b)

const int maxn=60000+10;
struct ST {
    int sum;
    int len;
    int lmax,rmax;
    int lazy;
} t[maxn<<2];

void build(int p,int l,int r) {
    const int L=r-l+1;
    t[p]= {L,L,L,L,0};

    if(l^r) {
        const int mid=(l+r)>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
    }
}

void pushdown(int p) {
    if(!t[p].lazy) return;

    if(t[p].lazy==1) {
        t[p<<1]= {0,t[p<<1].len,0,0,1};
        t[p<<1|1]= {0,t[p<<1|1].len,0,0,1};
    } else if(t[p].lazy==2) {
        t[p<<1]= {t[p<<1].len,t[p<<1].len,t[p<<1].len,t[p<<1].len,2};
        t[p<<1|1]= {t[p<<1|1].len,t[p<<1|1].len,t[p<<1|1].len,t[p<<1|1].len,2};
    }

    t[p].lazy=0;
}

void renew(int p) {
    if(t[p<<1].sum^t[p<<1].len) t[p].lmax=t[p<<1].lmax;
    else t[p].lmax=t[p<<1].len+t[p<<1|1].lmax;

    if(t[p<<1|1].sum^t[p<<1|1].len) t[p].rmax=t[p<<1|1].rmax;
    else t[p].rmax=t[p<<1|1].len+t[p<<1].rmax;

    t[p].sum=max(max(t[p<<1].sum,t[p<<1|1].sum),t[p<<1].rmax+t[p<<1|1].lmax);
}

void opt(int p,int l,int r,int tag,const int&tl,const int&tr) {
    pushdown(p);

    if(tl<=l&&tr>=r) {
        if(tag^2) {
            t[p]= {0,t[p].len,0,0,tag};
        } else {
            t[p]= {t[p].len,t[p].len,t[p].len,t[p].len,tag};
        }
    } else {
        const int mid=(l+r)>>1;

        if(tl<=mid) opt(p<<1,l,mid,tag,tl,tr);

        if(tr>mid) opt(p<<1|1,mid+1,r,tag,tl,tr);

        renew(p);
    }
}

int query(int p,int l,int r,int length) {
    pushdown(p);

    if(l^r) {
        const int mid=(l+r)>>1;

        if(t[p<<1].sum>=length) {
            return query(p<<1,l,mid,length);
        }

        if(t[p<<1].rmax+t[p<<1|1].lmax>=length) {
            return mid-t[p<<1].rmax+1;
        }

        return query(p<<1|1,mid+1,r,length);
    } else {
        return l;
    }
}

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    build(1,1,n);

    for(int i=1; i<=m; i++) {
        int op;
        scanf("%d",&op);

        if(op==1) {
            int x;
            scanf("%d",&x);

            if(t[1].sum>=x) {
                int left=query(1,1,n,x);
                printf("%d\n",left);
                opt(1,1,n,1,left,left+x-1);
            } else {
                printf("0\n");
            }
        } else {
            int x,y;
            scanf("%d%d",&x,&y);
            opt(1,1,n,2,x,x+y-1);
        }
    }



    return 0;
}
