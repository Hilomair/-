#include <bits/stdc++.h>

using namespace std;

int gcdEx(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        cout<<a<<" "<<b<<" "<<*x<<" "<<*y<<"\n";
        return a;
    }
    else
    {
        int r = gcdEx(b,a%b,x,y);
        int t = *x;
        *x = *y;
        *y = t - a/b * (*y);
        cout<<a<<" "<<b<<" "<<*x<<" "<<*y<<" "<<r<<" "<<t<<"\n";
        return r;
    }
}

int main()
{
    int a=47,b=30,x=1,y=0;
    int ans = gcdEx(a,b,&x,&y);
    cout<<ans<<"\n";
    return 0;
}
