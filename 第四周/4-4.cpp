#include<iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a-=c;
    b-=d;
    if(a<0) a*=-1;
    if(b<0) b*=-1;
    a=a*2+b*2;
    cout<<a;
    return 0;
}
