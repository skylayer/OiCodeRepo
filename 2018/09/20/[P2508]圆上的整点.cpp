#include<bits/stdc++.h>
using namespace std;
unsigned long long r,r2,anss;




int main() {
    cin>>r;
    r2=r*r;

    for(int i=(long double)r/2*sqrtl(2); i<r; ++i) {
        long double ans=sqrtl(r2-i*i);

        if(ans==floor(ans)) anss++;
    }

    cout<<anss*8+4;

    return 0;
}
