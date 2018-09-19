#include<bits/stdc++.h>
using namespace std;
const int reg[][10]= {
    {},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},
};
const int reward[10][10]= {
    {},
    {0,6,6,6,6, 6,6,6,6,6},
    {0,6,7,7,7, 7,7,7,7,6},
    {0,6,7,8,8, 8,8,8,7,6},
    {0,6,7,8,9, 9,9,8,7,6},
    {0,6,7,8,9,10,9,8,7,6},
    {0,6,7,8,9, 9,9,8,7,6},
    {0,6,7,8,8, 8,8,8,7,6},
    {0,6,7,7,7, 7,7,7,7,6},
    {0,6,6,6,6, 6,6,6,6,6},
};

bool row[10][10],column[10][10],sqr[10][10];
int r[10],c[10],s[10];
int src[10][10];
int ans;

inline int getreg(int x,int y) {
    return reg[x][y];
}

struct ps {
    int x,y;
    inline bool operator<(ps a) const {
        return r[x]+c[y]+s[getreg(x,y)]>r[a.x]+c[a.y]+s[getreg(a.x,a.y)];
    }
} p[90];
int cnt;


inline void init() {
    for(int i=1; i<=9; i++) {
        row[i][1]=1;
        row[i][2]=1;
        row[i][3]=1;
        row[i][4]=1;
        row[i][5]=1;
        row[i][6]=1;
        row[i][7]=1;
        row[i][8]=1;
        row[i][9]=1;
        sqr[i][1]=1;
        sqr[i][2]=1;
        sqr[i][3]=1;
        sqr[i][4]=1;
        sqr[i][5]=1;
        sqr[i][6]=1;
        sqr[i][7]=1;
        sqr[i][8]=1;
        sqr[i][9]=1;
        column[i][1]=1;
        column[i][2]=1;
        column[i][3]=1;
        column[i][4]=1;
        column[i][5]=1;
        column[i][6]=1;
        column[i][7]=1;
        column[i][8]=1;
        column[i][9]=1;
    }
}

inline void input() {
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            scanf("%d",&src[i][j]);

            if(src[i][j]) {
                ans+=src[i][j]*reward[i][j];
//				printf("ans=%d\n",ans);
                row[i][src[i][j]]=0;
                r[i]++;
                column[j][src[i][j]]=0;
                c[j]++;
                sqr[getreg(i,j)][src[i][j]]=0;
                s[getreg(i,j)]++;
            } else {
//				printf("%d %d\n",i,j);
                p[++cnt]= {i,j};
            }
        }
    }
}

int maxx=-1;

void dfs(int now) {
    if(now>cnt) {
//		printf("^^ans=%d\n",ans);
        if(maxx<ans) maxx=ans;

        return;
    }

//	for(int i=1;i<=9;i++) {
//		for(int j=1;j<=9;j++) {
//			printf("%d",src[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
    int x=p[now].x,y=p[now].y;

    for(int i=1; i<=9; i++) {
        if(row[x][i]&&column[y][i]&&sqr[getreg(x,y)][i]) {
            row[x][i]=column[y][i]=sqr[getreg(x,y)][i]=0;
            int tmp=ans;
            ans+=i*reward[x][y];
            src[x][y]=i;
//			printf("ans=%d\n",ans);
            dfs(now+1);
            src[x][y]=0;
            ans=tmp;
            row[x][i]=column[y][i]=sqr[getreg(x,y)][i]=1;
        }
    }
}

int main() {
//	freopen("ana.txt","w",stdout);
    init();
    input();
    sort(p+1,p+cnt+1);
    dfs(1);
    printf("%d",maxx);


    return 0;
}
