#include<iostream>

using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        for(int i=1;i<=a;i++)
            cout<<i<<"\n";
        for(int i=a-1;i>=1;i--)
            cout<<i<<"\n";
    }
    return 0;
}
