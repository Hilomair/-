#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int T,m[2],c[10005],W;
    while(cin>>m[0]>>m[1]>>T)
    {
        W=T;
        memset(c,-1,sizeof(c));
        c[0]=0;
        for(int i=0;i<2;i++)
            for(int j=m[i];j<=T;++j)
                if(c[j-m[i]]!=-1)
                    c[j]=max(c[j],c[j-m[i]]+1);
        while(c[W]==-1) W--;
        T-=W;
        if(T!=0)
            cout<<c[W]<<" "<<T;
        else
            cout<<c[W];
        cout<<"\n";
    }
    return 0;
}
