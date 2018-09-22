#include<bits/stdc++.h>
using namespace std;
int n;
unordered_map<string,map<string,int>>lst;
int ans;



int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        string a,b;
        cin>>a>>b;
        a=a.substr(0,2);

//		cout<<a<<b<<endl;
        if(a!=b)
            ans+=lst[b][a];

        lst[a][b]++;
    }

    printf("%d",ans);


    return 0;
}
