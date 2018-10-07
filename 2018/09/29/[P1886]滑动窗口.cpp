#include<bits/stdc++.h>
using namespace std;


int num[(int)1e6+10];
deque<pair<int,int>>rmq;
int n,k;





int main() {
    scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]);

    for(int i=1; i<k; i++) {
        while(!rmq.empty()&&rmq.back().second>=num[i])
            rmq.pop_back();

        rmq.push_back({i,num[i]});
    }

    for(int i=k; i<=n; i++) {
        while(!rmq.empty()&&rmq.front().first<=i-k)
            rmq.pop_front();

        while(!rmq.empty()&&rmq.back().second>=num[i])
            rmq.pop_back();

        rmq.push_back({i,num[i]});
        cout<<rmq.front().second<<' ';
    }

    printf("\n");
    rmq.clear();

    for(int i=1; i<k; i++) {
        while(!rmq.empty()&&rmq.back().second<=num[i])
            rmq.pop_back();

        rmq.push_back({i,num[i]});
    }

    for(int i=k; i<=n; i++) {

        while(!rmq.empty()&&rmq.front().first<=i-k)
            rmq.pop_front();

        while(!rmq.empty()&&rmq.back().second<=num[i])
            rmq.pop_back();

        rmq.push_back({i,num[i]});
        cout<<rmq.front().second<<' ';
    }

    printf("\n");


    return 0;
}
