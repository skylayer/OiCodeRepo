#include<bits/stdc++.h>
using namespace std;

const long double pi=3.14159265358979323846264338327950288419716939937510;



int R;
int main() {
    cin>>R;
    long double ans=R*sinl(pi/17)*R*cosl(pi/17)*17;
    cout<<setprecision(6)<<fixed<<ans;


    return 0;
}
