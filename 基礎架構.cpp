#include <bits/stdc++.h>

using namespace std;
int a[100005]={0},b[100005]={0},c[100005],d[100005];
int main()
{
    long long n,x;
    cin>>n>>x;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        a[tmp]++;
        c[i] = tmp;
        tmp&=x;
        b[tmp]++;
        d[i] = tmp;
    }
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=2)
        {
            cout<<"0";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]>a[i] && a[i]!=0)
        {
            cout<<"1";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]>=2)
        {
            cout<<"2";
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
