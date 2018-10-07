#include<bits/stdc++.h>
using namespace std;
const int p=9999991;
int ans=1,n;



int main() {
    scanf("%d",&n);

    for(int i=1; i<=n-2; i++) ans=(long long)ans*n%p;

    for(int i=1; i<n; i++) ans=(long long)ans*i%p;

    printf("%d",ans);



    return 0;
}
