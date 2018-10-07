#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
unordered_map<long long,int>lst;


int main() {
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++) {
        int h;
        scanf("%d",&h);
        ans+=lst[i-h];
        ans+=lst[i+h];
//		printf("ans+=lst[%d]=%d,ans+=lst[%d]=%d\n",i-h,lst[i-h],i+h,lst[i+h]);
        lst[i+h]++;
        lst[i-h]++;
//		printf("lst[%d]++,lst[%d]++\n",i-h,i+h);
    }

    printf("%lld",ans);

    return 0;
}
