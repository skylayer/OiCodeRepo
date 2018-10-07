#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int ans=0;
	
	for(int i=1;i<=2015;i++) {
		if((i%4!=0)&&(i%6!=0)&&(i%5!=0)) ans++;
	}
	cout<<ans;
}
