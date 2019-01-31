#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(pair<char,int> a,pair<char,int> b)
{
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}


int main()
{
    int T,color_num,tmp;
    pair<char,int> A[7],B[7],a[7],b[7];
    char color,c;
    cin>>T;
    while(T--)
    {
        cin>>A[0].first>>c;
        if(c>='A'&&c<='Z')
            A[0].second=c-'A';
        else
            A[0].second=c-'0';
        cin>>A[1].first>>c;
        if(c>='A'&&c<='Z')
            A[1].second=c-'A';
        else
            A[1].second=c-'0';
        cin>>B[0].first>>c;
        if(c>='A'&&c<='Z')
            B[0].second=c-'A';
        else
            B[0].second=c-'0';
        cin>>B[1].first>>c;
        if(c>='A'&&c<='Z')
            B[1].second=c-'A';
        else
            B[1].second=c-'0';
        for(int i=2;i<7;i++)
        {
            cin>>A[i].first>>c;
            if(c>='A'&&c<='Z')
                A[i].second=c-'A';
            else
                A[i].second=c-'0';
            B[i].first=A[i].first;
            B[i].second=A[i].second;
        }
        for(int i=0;i<7;i++)
        {
            a[i]=A[i];
            b[i]=B[i];
        }
        sort(A,A+7);
        sort(B,B+7);
        sort(a,a+7,cmp);
        sort(b,b+7,cmp);
        color=A[0].first;
        color_num=1;
        tmp=1;
        for(int i=0;i<7;i++)
        {
            cout<<A[i].first<<A[i].second<<" ";
            /*if(A[i-1].first!=A[i].first)
            {
                if(tmp>color_num)
                {
                    color_num=tmp;
                    color=A[i-1].first;
                }
                tmp=1;
            }
            tmp++;*/
        }
        cout<<"\n";
    }
    return 0;
}
