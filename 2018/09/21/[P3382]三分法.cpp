#include<bits/stdc++.h>
using namespace std;
long double coe[15],l,r;
int n;

long double f(long double x) {
    long double ans=0;

    for(int i=n; i>=0; i--)
        ans=ans*x+coe[i];

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin>>n>>l>>r;

    for(int i=n; i>=0; i--)
        cin>>coe[i];

    while(r-l>1e-6) {
        long double nl=l+(r-l)/3,nr=r-(r-l)/3;

        if(f(nl)<=f(nr)) l=nl;
        else r=nr;
    }

    cout<<setprecision(5)<<fixed<<r;


    return 0;
}
