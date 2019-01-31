#include<iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int M,a[3],d,ans[12],tmp[12],cnt;
    cin>>M;
    for(int I=1;I<=M;I++)
    {
        cnt=2;
        for(int i=0;i<12;i++)
            tmp[i]=0;
        cin>>a[2]>>a[1]>>a[0]>>d;
        ans[0]=a[0];
        ans[1]=a[1];
        ans[2]=a[2];
        while(d--)
        {
            for(int j=2;j>=0;j--)
                for(int k=cnt;k>=0;k--)
                    tmp[j+k]+=ans[k]*a[j];
            cnt+=2;
            for(int j=cnt;j>=0;j--)
                ans[j]=tmp[j];
            for(int i=0;i<12;i++)
                tmp[i]=0;
        }
        for(int i=cnt;i>=0;--i)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
