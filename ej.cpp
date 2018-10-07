#include<cstdio>
int a,b,c,d,
    e,f,g,h,i,j=0;
int k[2001]= {};
struct edge {
    int l,m;
    double n;
} o[300001];
bool vis[2001]= {};
double dis[2001]= {};
int cunt[30001];
inline void q(int c,int d,double p) {
    j++;
    o[j].l=d;
    o[j].n=1-p;
    o[j].m=k[c];
    k[c]=j;
    j++;
    o[j].l=c;
    o[j].n=1-p;
    o[j].m=k[d];
    k[d]=j;
}
int main() {
    scanf("%d%d",&a,&b);

    for(int r=1; r<=b; r++) {
        scanf("%d%d%d",&c,&d,&e);
        q(c,d,(double)e/100.0);
    }

    scanf("%d%d",&h,&i);
    f=g=1;
    cunt[f]=h;
    dis[h]=1;
    vis[h]=1;

    while(f<=g) {
        for(int r=k[cunt[f]];
                r; r=o[r].m) {
            if(dis[o[r].l]<
                    dis[cunt[f]]*o[r].n) {
                dis[o[r].l]=
                    dis[cunt[f]]*o[r].n;

                if(!vis[o[r].l]) {
                    g++;
                    cunt[g]=o[r].l;
                    vis[o[r].l]=0;
                }
            }

        }

        vis[cunt[f]]=0;
        f++;
    }

    printf("%.8f\n",100/dis[i]);
    return 0;
}

