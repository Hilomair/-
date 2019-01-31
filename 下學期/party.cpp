#include <bits/stdc++.h>

using namespace std;

int r[1003];
vector<int> s[1003];
pair<int,int> dp[1003];

void dfs(int n)
{
    if(s[n].empty())
        return;
    for(int i=0;i<s[n].size();i++)
    {
        dfs(s[n][i]);
        dp[n].first += dp[s[n][i]].second;
        dp[n].second += max(dp[s[n][i]].first,dp[s[n][i]].second);
    }
    return;
}

int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<1003;i++)
            s[i].clear();
        cin>>n>>r[1];
        dp[1].first = r[1];
        dp[1].second = 0;
        for(int i=2;i<=n;i++)
        {
            int tmp;
            cin>>tmp>>r[i];
            dp[i].first = r[i];
            dp[i].second = 0;
            s[tmp].push_back(i);
        }
        dfs(1);
        long long ans = max(dp[1].first,dp[1].second);
        //cout<<dp[1].first<<" "<<dp[1].second<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}
