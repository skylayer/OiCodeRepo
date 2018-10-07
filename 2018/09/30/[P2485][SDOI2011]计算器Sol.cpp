#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;
long long pow_mod(long long a,long long b,long long p) {
    long long ans=1;

    while(b) {
        if(b&1) {
            ans=(long long)ans*a%p;
        }

        a=(long long)a*a%p;
        b=b/2;
    }

    return ans;
}//快速幂求解
long long exgcd(long long a,long long b,long long &x1,long long &y2) {
    if(b==0) {
        x1=1,y2=0;
        return a;
    }

    long long d=exgcd(b,a%b,x1,y2);
    long long z=x1;
    x1=y2;
    y2=z-y2*(a/b);
    return d;
}//拓展欧几里得算法
long long baby_step_giant_step(long long a,long long b,long long p) {
    map<long,long>hash;
    hash.clear();
    b%=p;
    int t=(int)sqrt(p)+1;

    for(int j=0; j<t; j++) {
        int val=(long long)b*pow_mod(a,j,p)%p;
        hash[val]=j;
    }

    a=pow_mod(a,t,p);

    if(a==0) {
        if(b==0) {
            return 1;
        } else {
            return -1;
        }
    }

    for(int i=0; i<=t; i++) {
        int val=pow_mod(a,i,p);
        int j=hash.find(val)==hash.end()?-1:hash[val];

        if(j>=0&&i*t-j>=0) {
            return i*t-j;
        }
    }

    return -1;
}//求高次同余方程
int main() {
    long long t,k,z,y,p;
    scanf("%lld %lld",&t,&k);  //注意要开long long 类型，否则会溢出

    while(t--) {
        if(k==1) {
            scanf("%lld%lld%lld",&y,&z,&p);
            printf("%lld\n",pow_mod(y,z,p));
        } else if(k==2) {
            scanf("%lld%lld%lld",&y,&z,&p);
            long long x=0,yy=0,gcd=0;
            gcd=exgcd(y,p,x,yy);

            if(z%gcd==0) {
                long long tmp=p/gcd;
                x=(((x*z)/gcd)%tmp+tmp)%tmp;  //对x进行处理
                printf("%lld\n",x);
            } else {
                printf("Orz, I cannot find x!\n");
            }
        } else if(k==3) {
            scanf("%lld%lld%lld",&y,&z,&p);
            long long ans=baby_step_giant_step(y,z,p);

            if(ans==-1) { //方程无解
                printf("Orz, I cannot find x!\n");
            } else {
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
