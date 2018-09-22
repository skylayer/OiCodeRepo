#include<bits/stdc++.h>
using namespace std;
int n;
struct com {
    int a,b;
} o[100001];

struct cmp {
    inline bool operator()(const com&a,const com&b) const {
        return a.b<b.b;
    }
};


int main() {
    scanf("%d",&n);

    for(int i=1; i<=n; i++) scanf("%d",&o[i].a);

    for(int i=1; i<=n; i++) scanf("%d",&o[i].b);

    sort(o+1,o+1+n,cmp());


    return 0;
}
