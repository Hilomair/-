#include<iostream>

using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
    int a,ans1,ans2,ans3,ans4;
    cin>>a;
    ans1=a/50;
    a%=50;
    ans2=a/10;
    a%=10;
    ans3=a/5;
    a%=5;
    ans4=a;
    cout<<ans1<<"\n"<<ans2<<"\n"<<ans3<<"\n"<<ans4;
    return 0;
}
