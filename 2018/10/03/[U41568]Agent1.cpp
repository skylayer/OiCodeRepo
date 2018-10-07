#include<bits/stdc++.h>
using namespace std;
const int inv2=500000004;
const int p=1e9+7;

int n;


inline int fpow(int index) {
    long long base=2,ans=1;

    while(index) {
        if(index&1) ans=ans*base%p;

        base=base*base%p;
        index>>=1;
    }

    return ans;
}


long long ans;

long long bot,top;

int main() {
//	cout<<fpow(p-2)<<endl;
    scanf("%d",&n);
    cout<<((long long)n*fpow(n-1)-fpow(n)+1)%p;





    return 0;
}
