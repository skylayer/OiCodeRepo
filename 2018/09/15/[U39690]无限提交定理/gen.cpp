#include<bits/stdc++.h>
using namespace std;


int main() {
    mt19937 gen(time(0));

    for(int i=1; i<=50; i++) {
        char filename[30];
        sprintf(filename,"game%d.in",i);
        freopen(filename,"w",stdout);
        printf("%d",i);
        sprintf(filename,"game%d.out",i);
        freopen(filename,"w",stdout);
        printf("%d",gen()%10007);
    }


    return 0;
}
