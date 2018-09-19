#include <iostream>
using namespace std ;
#define rd(x) (rand()%(x))
typedef unsigned long long ll;

ll pow_mod(ll a,ll b,ll r)
{
    ll ans=1,buff=a;

    while(b)
        {
            if(b&1)
                ans=(ans*buff)%r;

            buff=(buff*buff)%r;
            b>>=1;
        }

    return ans;
}

bool test(ll n,ll a,ll d)
{
    if(n==2) return true;

    if(n==a) return false;

    if(!(n&1)) return false;

    while(!(d&1)) d>>=1;

    ll t = pow_mod(a,d,n);

    while(d!=n-1&&t!=n-1&&t!=1)
        {
            t = t*t%n;
            d<<=1;
        }

    return t == n-1||(d&1)==1;
}

bool isprime(ll n)
{
    int a[] = {2,3,5,7};

    for(int i = 0; i <= 3; ++i)
        {
            if(n==a[i]) return true;

            if(!test(n,a[i],n-1)) return false;
        }

    return true;
}
int n;
int main()
{
    scanf("%d",&n);

    for(int i=n; i>=2; i--)
        {
            if(i>5&&(i%6!=1&&i%6!=5)) continue;

            if(isprime(i))
                {
                    printf("%d",i);
                    return 0;
                }
        }

    return 0;
}
