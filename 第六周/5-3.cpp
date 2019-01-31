#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int T,a;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            for(int k=1;k<=j;k++)
                cout<<k;
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
