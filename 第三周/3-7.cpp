#include<iostream>

using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
    int a,b,c,d,area,pmeter;
    cin>>a>>b>>c>>d;
    area=(c-a)*(d-b);
    pmeter=(c-a)*2+(d-b)*2;
    cout<<area<<" "<<pmeter;
    return 0;
}
