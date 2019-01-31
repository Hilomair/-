#include<iostream>

using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
    int a,b,c,D;
    cin>>a>>b>>c;
    D=b*b-4*a*c;
    if(D==0)
        cout<<1;
    else
        cout<<0;
    return 0;
}
