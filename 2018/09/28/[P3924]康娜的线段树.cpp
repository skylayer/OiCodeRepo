#include<bits/stdc++.h>
using namespace std;



void read(long long &x) {
    x=0;
    long long f=1;
    char s=getchar();

    while(s<'0'||s>'9') {
        if(s=='-')f=-1;

        s=getchar();
    }

    while(s>='0'&&s<='9') {
        x=x*10+s-'0';
        s=getchar();
    }

    x*=f;
}


long long dep[(int)1e6+10],frt[(int)1e6+10];
int mdp;
void gd(int l,int r,int dth) {
    mdp=max(mdp,dth);

    if(l^r) {
        gd(l,(l+r)>>1,dth+1);
        gd(((l+r)>>1)+1,r,dth+1);
    } else dep[l]=dth;
}

long long n,m,qaq;




int main() {
    read(n),read(m),read(qaq);

    gd(1,n,0);


    long long up=0,down=1ll<<mdp;

    for(int i=1; i<=n; i++) {
        long long num;
        read(num);
        frt[i]=(1<<mdp+1)-1;
        frt[i]^=(1<<mdp-dep[i])-1;
        up+=frt[i]*num;
    }

    for(int i=1; i<=n; i++)
        frt[i]=frt[i-1]+frt[i];

    long long gcd=__gcd(qaq,down);
    qaq/=gcd,down/=gcd;
//	cout<<(double)up*qaq/down<<endl;

    for(int i=1; i<=m; i++) {
        long long l,r,k;
        read(l),read(r),read(k);
        printf("%lld\n",(up+=(frt[r]-frt[l-1])*k)*qaq/down);
    }





    return 0;
}
