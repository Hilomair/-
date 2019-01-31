#include <bits/stdc++.h>

using namespace std;
int dp[101][101];
int t,n,k,p[101];

int cut(int l,int r)
{
    if(dp[l][r]!=1e9)   return dp[l][r];
    int flag=0;
    for(int i=0;i<k;i++)
        if(p[i]>l&&p[i]<r)
        {
            flag=1;
            dp[l][r] = min(dp[l][r],cut(l,p[i])+cut(p[i],r)+r-l);
        }
    if(!flag)
        dp[l][r]=0;
    return dp[l][r];
}


int main()
{

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<k;i++)
            cin>>p[i];
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                dp[i][j]=1e9;
        cut(0,n);
        cout<<dp[0][n]<<"\n";
    }
    return 0;
}
