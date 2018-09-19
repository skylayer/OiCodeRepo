#include<bits/stdc++.h>
using namespace std;

map<string,string>num2reg;

string id;
void work()
{
    cin>>id;
    string region=num2reg[id.substr(0,2)];
    string y=id.substr(6,4),m=id.substr(10,2),d=id.substr(12,2);
    cout<<"He/She is from "<<region<<",and his/her birthday is on "<<m<<','<<d<<','<<y<<" based on the table.\n";
}
int main()
{
    num2reg["33"]="Zhejiang";
    num2reg["11"]="Beijing";
    num2reg["71"]="Taiwan";
    num2reg["81"]="Hong Kong";
    num2reg["82"]="Macao";
    num2reg["54"]="Tibet";
    num2reg["21"]="Liaoning";
    num2reg["31"]="Shanghai";
    int _;
    scanf("%d",&_);

    while(_--) work();

    return 0;
}
