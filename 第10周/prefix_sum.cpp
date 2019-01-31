#include<iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int N,K,a,b,n[100001];
    cin>>N>>K;
    n[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin>>n[i];
        n[i]+=n[i-1];
    }
    for(int i=1;i<=K;i++)
    {
        cin>>a>>b;
        if(a>b)
           a^=b^=a^=b;
        cout<<n[b]-n[a-1]<<"\n";
    }
    return 0;
}
