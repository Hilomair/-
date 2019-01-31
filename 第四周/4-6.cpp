#include<iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b<c)
        cout<<0;
    else if(b+c<a)
        cout<<0;
    else if(a+c<b)
        cout<<0;
    else
        cout<<1;
    return 0;
}
