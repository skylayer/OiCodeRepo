#include<bits/stdc++.h>
using namespace std;

long long fpow(long long base,long long index,long long p) {
    long long ans=1;

    while(index) {
        if(index&1) ans=ans*base%p;

        base=base*base%p;
        index>>=1;
    }

    return ans;
}

long long exgcd(long long a,long long b,long long &x1,long long &y2) {
    if(!b) {
        x1=1,y2=0;
        return a;
    }

    long long d=exgcd(b,a%b,x1,y2);
    long long z=x1;
    x1=y2;
    y2=z-y2*(a/b);
    return d;
}

long long bsgs(long long a,long long b,long long p) {
    map<long long,long long>hash;
    hash.clear();
    b%=p;
    int t=(int)sqrt(p)+1;

    for(int j=0; j<t; j++) {
        int val=(long long)b*fpow(a,j,p)%p;
        hash[val]=j;
    }

    a=fpow(a,t,p);

//	printf("a=%d\n",a);
    if(!a) {
        if(!b) return 1;

        return -1;
    }

    for(int i=0; i<=t; i++) {
        int val=fpow(a,i,p);
        int j=hash.find(val)==hash.end()?-1:hash[val];

        if(j>=0&&i*t-j>=0) return i*t-j;
    }

    return -1;
}


int main() {

    long long y,z=1,p;
    cin>>y>>p;
    long long x=0,yy=0,gcd=0;
    gcd=exgcd(y,p,x,yy);

    if(z%gcd==0) {
        long long tmp=p/gcd;
        x=((x*z/gcd)%tmp+tmp)%tmp;
        printf("%d\n",x);
    } else printf("Orz, I cannot find x!\n");



    return 0;
}
