#include<iostream>

using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
    int a,b=0;
    cin>>a;
    for(int i=1;i<=4;i++)
    {
        b+=a%10;
        a/=10;
    }
    cout<<b<<"\n";
    return 0;
}
