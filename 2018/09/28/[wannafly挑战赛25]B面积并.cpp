#include<bits/stdc++.h>
using namespace std;
const long double pi=3.14159265358979323846264338327950288419716939937510;
int n,l,r;




int main() {
    scanf("%d%d%d",&n,&l,&r);
//	cout<<pi/n;
    long double h=(long double)l*cosl(pi/n);
    cout<<asinl(h/r)<<endl;
    long double alpha=asinl(h/r);
    cout<<alpha<<endl;
    long double size=alpha*r*r;
    cout<<size<<endl;
    long double base=(long double)l*sinl(pi/n)-alpha*r;
    size+=h*base;
    size*=n;
    cout<<size;


    return 0;
}
