#include <bits/stdc++.h>

using namespace std;
int a[30],ans_max,ans_min,N;
long long board[30][30];

bool check(int n)
{
    for(int i=0;i<n;i++)
        if(abs(a[i]-a[n]) == abs(i-n) )
            return 1;
    return 0;
}

void _count()
{
    int tmp = 0;
    for(int i=0;i<N;i++)
    {
        int column = i;
        int row    = a[i];
        tmp += board[column][row];
    }
    ans_max = max(ans_max,tmp);
    ans_min = min(ans_min,tmp);
}

void enumerate(int beg)
{
    if(beg == N-1)
    {
        if(!check(beg))
            _count();
        return;
    }

    for(int i=beg;i<N;i++)
    {
        swap(a[beg],a[i]);
        if(!check(beg))
            enumerate(beg+1);
        swap(a[beg],a[i]);
    }

}


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>board[i][j];
        for(int i=0;i<N;i++)
            a[i] = i;
        ans_max = -1;
        ans_min = 1e9;
        enumerate(0);
        cout<<ans_max<<" "<<ans_min<<"\n";
    }
    return 0;
}
