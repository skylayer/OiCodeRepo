#include<bits/stdc++.h>
#define Ls o<<1
#define Rs o<<1|1
using namespace std;
typedef long long LL;
const int N=2e5 + 7,Nd=N<<2;
LL n,m,tp;
LL g[Nd],A[N],St[N];
LL tr[N];
LL gcd(LL a,LL b) {
    if(!b) return a;

    return gcd(b,a%b);
}
LL lowbit(LL x) {
    return x&-x;
}
void modify(LL x,LL y) {
    for(LL i=x; i<=n; i+=lowbit(i)) tr[i]+=y;
}
LL query(LL x) {
    LL res=0;

    for(LL i=x; i; i-=lowbit(i)) res+=tr[i];

    return (LL)res;
}
void up(LL l,LL r,LL x) {
    modify(l,x),modify(r+1,-x);
}
void pushup(LL o) {
    g[o]=gcd(g[Ls],g[Rs]);
}
void build(LL l,LL r,LL o) {
    if(l==r) {
        g[o]=abs(A[l]-A[l+1]);
        return;
    }

    LL mid=l+r>>1;
    build(l,mid,Ls);
    build(mid+1,r,Rs);
    pushup(o);
}
void update(LL p,LL l,LL r,LL o) {
    if(l==r) {
        g[o]=abs(query(l)-query(l+1));
        return;
    }

    LL mid=l+r>>1;

    if(p<=mid) update(p,l,mid,Ls);
    else update(p,mid+1,r,Rs);

    pushup(o);
}
LL query(LL L,LL R,LL l,LL r,LL o) {
    if(L<=l&&r<=R) return g[o];

    LL mid=l+r>>1;

    if(R<=mid) return query(L,R,l,mid,Ls);

    if(L>mid)  return query(L,R,mid+1,r,Rs);

    return gcd(query(L,R,l,mid,Ls),query(L,R,mid+1,r,Rs));
}
inline LL gi() {
    LL x=0,f=1;
    char ch=getchar();

    while(!isdigit(ch)) {
        if(ch=='-') f=-1;

        ch=getchar();
    }

    while(isdigit(ch)) {
        x=(x<<3)+(x<<1)+ch-48;
        ch=getchar();
    }

    return x*f;
}
int main() {
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    scanf("%lld%lld",&n,&m);

    for(LL i=1; i<=n; i++) A[i]=gi(),up(i,i,A[i]);

    build(1,n-1,1);
    LL opt,l,r,v;

    while(m--) {
        scanf("%lld%lld%lld",&opt,&l,&r);

        if(l>r) swap(l,r);

        if(opt==1) {
            scanf("%lld",&v);
            up(l,r,v);

            if(l^1) update(l-1,1,n-1,1);

            if(r^n) update(r,1,n-1,1);
        } else {
            if(l==r) {
                printf("%lld\n",query(l));
                continue;
            }

            printf("%lld\n",gcd(query(l),query(l,r-1,1,n-1,1)));
        }
    }

    return 0;
}
