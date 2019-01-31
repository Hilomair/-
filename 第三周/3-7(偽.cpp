#include<iostream>

using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
    double t1,t2,a,b,c,d;
    cin>>a>>b>>c>>d;
    t1=(0-a)/(0-b);
    t2=(0-c)/(0-d);
    if(t1==t2)
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
    return 0;
}
