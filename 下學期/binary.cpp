#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string a;
    while(cin>>n)
    {
        if(!n)  break;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            long long tmp=1;
            for(int j=a.size()-1;j>=0;j--)
            {
                if(a[j]=='1')
                    ans+=tmp;
                tmp*=2;
            }
            //cout<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
