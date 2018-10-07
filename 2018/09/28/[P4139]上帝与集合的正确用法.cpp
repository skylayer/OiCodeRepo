// a^(b%phi(p)+phi(p)) gcd(a,p) != 1 b >= phi(p) (mod p)
#include<bits/stdc++.h>
using namespace std;


int fpow(int base,int index,int p) {
    int ans=1;

    while(index) {
        if(index&1) ans=(long long)ans*base%p;

        base=(long long)base*base%p;
        index>>=1;
    }

    return ans;
}

int phi(int x) {
    int ans=x;

    for(int i=2; i*i<=x; i++) {
        if(x%i) continue;

        ans=ans/i*(i-1);

        while(!(x%i)) x/=i;

//		printf("x=%d\n",x);
    }

    if(x^1) ans=ans/x*(x-1);

    return ans;
}

//typedef long long ll;
//ll phi(ll x)
//{
//    ll ans = x;
//    for(ll i = 2 ; i * i <= x ;i++)
//    {
//        if(x % i == 0)
//        {
//            ans = ans / i * (i - 1);
//            while(x % i == 0)
//            {
//                x /= i;
//            }
//        }
//    }
//    if(x != 1)
//    {
//        ans = ans / x * (x - 1);
//    }
//    return ans;
//}

int calc(int p) {
//	printf("%d\n",p);
    if(p^1) {
        int t=phi(p);
        return fpow(2,calc(t)+t,p);
    }

    return 0;
}

int main() {
//	cout<<phi(6);
    int T;
    scanf("%d",&T);

    while(T--) {
        int p;
        scanf("%d",&p);
        cout<<calc(p)<<endl;
    }




    return 0;
}
