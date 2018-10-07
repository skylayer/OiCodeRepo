#include<bits/stdc++.h>
using namespace std;
char s[110];
int f[101][101];


int main() {
    scanf("%s",s+1);
    int len=strlen(s+1);

    for(int i=len-1; i>=1; i--) {
        for(int j=i+1; j<=len; j++) {
            if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')) f[i][j]=f[i+1][j-1]+2;

            for(int k=i; k<j; k++) f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
        }

    }

    printf("%d\n",len-f[1][len]);
    return 0;
}
