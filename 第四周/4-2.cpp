#include<iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int x1,x2,x3,y1,y2,y3,L1,L2,L3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    L1=x1*x1+y1*y1;
    L2=x2*x2+y2*y2;
    L3=x3*x3+y3*y3;
    if(L1>=L2 && L1>=L3)
        cout<<x1<<"\n"<<y1;
    else if(L2>=L3 && L2>=L1)
        cout<<x2<<"\n"<<y2;
    else
        cout<<x3<<"\n"<<y3;
    return 0;
}
