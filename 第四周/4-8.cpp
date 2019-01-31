#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int a,b,c,tmp;
    cin>>a>>b>>c;
    if(b<c)
        swap(b,c);
    if(a<b)
        swap(a,b);
    tmp=b*b+c*c;
    if(a*a<tmp)
        cout<<1;
    else if(a*a>tmp)
        cout<<2;
    else
        cout<<3;
    return 0;
}
