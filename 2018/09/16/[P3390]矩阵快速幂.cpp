#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

struct matrix
{
    long long m[101][101];
    long long n=2;
    inline matrix operator*(matrix&b) const
    {
        matrix ne;

        for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                    {
                        ne.m[i][j]=0;
                    }
            }

        for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                    {
                        for(int k=1; k<=n; k++)
                            {
                                ne.m[i][j]=ne.m[i][j]%mod+m[i][k]*b.m[k][j]%mod;
                            }
                    }
            }

        return ne;
    }
};

matrix e;

inline matrix fpow(register matrix base,long long index)
{
    register matrix x=e;

    while(index)
        {
            if(index&1) x=x*base;

            base=base*base;
            index>>=1;
        }

    return x;
}



int main()
{
    long long n;
    scanf("%lld",&n);

    for(int i=1; i<=2; i++) e.m[i][i]=1;

    if(n<=2)
        {
            printf("1");
            return 0;
        }

    register matrix st;

    for(int i=1; i<=2; i++)
        {
            for(int j=1; j<=2; j++)
                {
                    st.m[i][j]=1;
                }
        }

    st.m[2][2]=0;
    n-=2;
    matrix ans=fpow(st,n);
    long long tp[3]= {0,0,0},a[3]= {0,1,1};

    for(int i=1; i<=2; i++)
        {
            for(int j=1; j<=2; j++)
                {
                    tp[i]=(tp[i]+ans.m[i][j]*a[j]) % mod;
                }
        }

    printf("%lld",tp[1]);

    return 0;
}
