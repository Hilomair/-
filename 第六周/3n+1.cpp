#include<iostream>

using namespace std;

int main()
{
    int a,b,m=1,c,ans=0;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        if(a>b)
            swap(a,b);
        ans=0;
        for(int i=a;i<=b;i++)
        {
            c=i;m=1;
            while(c!=1)
            {
                if(c%2==0)
                {
                    c/=2;
                    m++;
                }
                else
                {
                    c=3*c+1;
                    m++;
                }
            }
            if(ans<m)   ans=m;
        }
        cout<<a<<" "<<b<<" "<<ans<<"\n";
    }
    return 0;
}
