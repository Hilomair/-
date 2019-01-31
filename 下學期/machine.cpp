#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,M,job,m[11];
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(int i=0;i<M;i++)
            m[i]=0;
        for(int i=0;i<N;i++)
        {
            cin>>job;
            sort(m,m+M);
            m[0]+=job;
        }
        sort(m,m+M);
        cout<<m[M-1];
        if(T)
            cout<<"\n";
    }
    return 0;
}
