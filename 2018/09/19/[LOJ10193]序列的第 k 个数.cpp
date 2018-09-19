#include<bits/stdc++.h>
using namespace std;
const int mod=200907;


void work() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    d--;

    if(b-a==c-b) {
        int k=b-a,ans=0;

        while(d) {
            if(d&1) ans=((long long)ans+k)%mod;

            d>>=1;
            k=((long long)k+k)%mod;
        }

        printf("%d\n",((long long)ans+a)%200907);
    } else {
        int k=b/a,ans=1;

        while(d) {
            if(d&1) ans=((long long)ans*k)%mod;

            d>>=1;
            k=((long long)k*k)%mod;
        }

        printf("%d\n",(long long)ans*a%200907);
    }



}




int main() {
    int T;
    scanf("%d",&T);

    while(T--)
        work();



    return 0;
}
