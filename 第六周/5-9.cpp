#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int T,ans[100],cnt,b;
    long long a;
    bool test,test2;
    cin>>T;
    while(T)
    {
        cnt=0;test=0;test2=0;
        for(int i=0;i<100;i++)
            ans[i]=0;

        cin>>a;

        b=sqrt(a);
        for(int i=2;i<=b;i++)
            if(a%i==0) {  test=1; break;}
        if(!test)
            cout<<a<<"\n"<<1<<"\n";
        if(test)
        {
            int j=2;
            while(a!=1)
            {
                test2=0;
                while(a%j==0)
                {
                    ans[cnt]=j;
                    ans[cnt+1]++;
                    a/=j;
                    test2=1;
                }
                if(test2) cnt+=2;
 //               if(a==1) break;
                j++;
            }
            for(int i=0;i<cnt;i++)
                cout<<ans[i]<<"\n";
        }
        cout<<"\n";
        T--;
    }
    return 0;
}
