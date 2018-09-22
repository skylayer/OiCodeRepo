#include<bits/stdc++.h>
using namespace std;
long double coe[(int)1e5+1][3],l,r;
int n;

inline long double fx(long double x,int pos) {
    long double ans=0;

    for(int i=2; i>=0; i--)
        ans=ans*x+coe[pos][i];

    return ans;
}

long double f(long double x) {
    long double ans=-1e333;

    for(int i=1; i<=n; i++) {
        long double a=fx(x,i);

        if(a>ans) ans=a;
    }

    return ans;
}

void work() {
    l=0,r=1e3;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>coe[i][2]>>coe[i][1]>>coe[i][0];

    while(r-l>1e-20) {
        long double nl=l+(r-l)/3,nr=r-(r-l)/3;

        if(f(nl)>=f(nr)) l=nl;
        else r=nr;
    }

    cout<<setprecision(4)<<fixed<<f(r)<<endl;
}

int main() {
    freopen("curves1.in","r",stdin);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;

    while(T--) work();


    return 0;
}
