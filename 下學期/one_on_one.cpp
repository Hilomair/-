#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,en[10005],so[10005];
    while(cin>>n)
    {
        if(!n)  break;
        for(int i=0;i<n;i++)
            cin>>en[i];
        for(int i=0;i<n;i++)
            cin>>so[i];
        sort(en,en+n);
        sort(so,so+n);
        long long tmp=n-1,ans=0;
        for(int i=n-1;i>=0;i--)
            if(so[tmp]>en[i])
            {
                ans++;
                tmp--;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
