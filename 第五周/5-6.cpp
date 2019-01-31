#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int T,y,m,d,test=0,ans;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;test=0;
        scanf("%d/%d/%d",&y,&m,&d);
        if((y%400==0)||((y%4==0)&&(y%100!=0)))
            test=1;
        if((y<1970)||(d>31))
            cout<<0;
        else if((d>30)&&((m==2)||(m==4)||(m==6)||(m==9)||(m==11)))
            cout<<0;
        else if((test&&(d>29)&&(m==2))||(!test&&(d>28)&&(m==2)))
            cout<<0;
        else if(m>12 || m<=0 || d<=0 ||y<=0)
            cout<<0;
        else
        {
            for(int j=1970;j<y;j++)
            {
                if((j%400==0)||((j%4==0)&&(j%100!=0)))
                     ans+=366;
                else
                    ans+=365;
            }
            for(int j=1;j<m;j++)
            {
                if((j==1)||(j==3)||(j==5)||(j==7)||(j==8)||(j==10)||(j==12))
                    ans+=31;
                else if((j==4)||(j==6)||(j==9)||(j==11))
                    ans+=30;
                else if(test && j==2)
                    ans+=29;
                else if(!test && j==2)
                    ans+=28;
            }

            ans+=d;
            cout<<ans;
        }
        if(i!=T)
            cout<<"\n";
    }
    return 0;
}
