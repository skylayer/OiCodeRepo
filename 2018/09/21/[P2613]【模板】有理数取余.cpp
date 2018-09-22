#include<bits/stdc++.h>
using namespace std;

const int mod=19260817;

int read() {
    long long ans=0;
    char v=getchar();

    while(isspace(v)) v=getchar();

    while(isdigit(v)) (ans=(ans<<3)+(ans<<1)+v-'0')%=mod,v=getchar();

    return ans;
}

int fpow(int base,int index) {
    long long ans=1;

    while(index) {
        if(index&1) ans=ans*base%mod;

        index>>=1;
        base=(long long)base*base%mod;
    }

    return ans;
}

int main() {
    int ans=(long long)read()*fpow(read(),mod-2)%mod;

    if(!ans) printf("Angry!");
    else
        printf("%d",ans);

    return 0;
}
