//#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


const int  arraylength=7;


struct player //set players
{
    char first;
    int second;
};
player A[7],B[7],ans_A[6],ans_B[6];

//typedef struct player Player;

int compare(const void *data1, const void *data2)
{
    player *ptr1 = (player *)data1;
    player *ptr2 = (player *)data2;
    if(ptr1->first==ptr2->first)
        if(ptr1->second>ptr2->second)
            return 1;
        else
            return 0;
    if(ptr1->first>ptr2->first)
        return 1;
    else
        return 0;
}

int compare2(const void *data1, const void *data2)
{
    player *ptr1 = (player *)data1;
    player *ptr2 = (player *)data2;
    if(ptr1->second == ptr2->second)
        if(ptr1->first > ptr2->first)
            return 1;
        else
            return 0;
    if(ptr1->second > ptr2->second)
        return 1;
    else
        return 0;
}

void change(char t[],int i) //change letters to numbers if they're T~A
{
    if(t[i]=='A')
    {
        t[i]='1';
        t[i+1]='4';
    }
    else if(t[i]=='T')
    {
        t[i]='1';
        t[i+1]='0';
    }
    else if(t[i]=='J')
    {
        t[i]='1';
        t[i+1]='1';
    }
    else if(t[i]=='Q')
    {
        t[i]='1';
        t[i+1]='2';
    }
    else if(t[i]=='K')
    {
        t[i]='1';
        t[i+1]='3';
    }
}

void cut(char in[],int cnt) //cut the string into each player
{
    char * c;
    c = strtok(in," ");
    while(c != NULL)
    {
        A[cnt].first=c[0];
        c[0]=c[1];
        c[1]='\0';
        change(c,0);
        A[cnt].second = atoi(c);
        cnt++;
        c = strtok(NULL, " ");
    }
}

void cp_A(int tmp)
{
    int i;
    for(i=1;i<=5;i++)
    {
        ans_A[i].first=A[tmp].first;
        ans_A[i].second=A[tmp].second;
        tmp++;
    }
}

void cp_B(int tmp)
{
    int i;
    for(i=1;i<=5;i++)
    {
        ans_B[i].first=B[tmp].first;
        ans_B[i].second=B[tmp].second;
        tmp++;;
    }
}

int StraightFlush_or_Flush_A()
{
    char most_color=A[6].first;
    int most_color_sum=1,cnt=1,i,flag,tmp_A,tmp;
    int re_brend=-1;
    for(i=arraylength-1;i>=0;i--)
    {
        if(A[i].first!=A[i-1].first && most_color_sum<cnt)
        {
            most_color=A[i].first;
            most_color_sum=cnt;
            tmp=i;
            cnt=1;
        }
        else if(i==0 && A[i].first==A[i+1].first)
        {
            cnt++;
            if(most_color_sum<cnt)
            {
                most_color=A[i].first;
                most_color_sum=cnt;
                tmp=i;
            }
            cnt=1;
        }
        if(A[i].first==A[i-1].first)
            cnt++;
    }
    flag=0;
    cnt=0;
    if(most_color_sum>=5)
    {
        for(i=arraylength-1;i>=0;i--)
        {
            if(cnt>=5)
                break;
            if(A[i].first==most_color)
            {
                if(!flag)
                {
                    cnt=1;
                    flag=1;
                    tmp=i;
                }
                else if(A[i+1].second-A[i].second==1)
                {
                    cnt++;
                    tmp_A=i;
                }
                else
                    cnt=1;
            }
        }
        //printf("%d\n",tmp_A);
        if(cnt>=5)
        {
            re_brend=9;
            cp_A(tmp_A);
        }
        else
        {
            tmp-=4;
            re_brend=6;
            cp_A(tmp);
        }
    }
    return re_brend;
}

int StraightFlush_or_Flush_B()
{
    char most_color=B[6].first;
    int most_color_sum=1,cnt=1,i,flag,tmp_A,tmp;
    int re_brend=-1;
    for(i=arraylength-1;i>=0;i--)
    {
        if(B[i].first!=B[i-1].first && most_color_sum<cnt)
        {
            most_color=B[i].first;
            most_color_sum=cnt;
            tmp=i;
            cnt=1;
        }
        else if(i==0 && B[i].first==B[i+1].first)
        {
            cnt++;
            if(most_color_sum<cnt)
            {
                most_color=B[i].first;
                most_color_sum=cnt;
                tmp=i;
            }
            cnt=1;
        }
        if(B[i].first==B[i-1].first)
            cnt++;
    }
    flag=0;
    cnt=0;
    if(most_color_sum>=5)
    {
        for(i=arraylength-1;i>=0;i--)
        {
            if(cnt>=5)
                break;
            if(B[i].first==most_color)
            {
                if(!flag)
                {
                    cnt=1;
                    flag=1;
                    tmp=i;
                }
                else if(B[i+1].second-B[i].second==1)
                {
                    cnt++;
                    tmp_A=i;
                }
                else
                    cnt=1;
            }
        }
        if(cnt>=5)
        {
            re_brend=9;
            cp_B(tmp_A);
        }
        else
        {
            tmp-=4;
            re_brend=6;
            cp_B(tmp);
        }
    }
    return re_brend;
}

int Straight_A()
{
    int i,cnt=5,tmp_A=arraylength-1,re_brend=-1,flag=0,tmp;
    for(i=arraylength-1;i>0;i--)
    {
        if(A[i].second==A[i-1].second && !flag)
        {
            flag=1;
            tmp=i;
        }
        else if(A[i].second-A[i-1].second==1)
        {
            if(flag)
            {
                ans_A[cnt].first=A[tmp].first;
                ans_A[cnt].second=A[tmp].second;
            }
            else
            {
                ans_A[cnt].first=A[i].first;
                ans_A[cnt].second=A[i].second;
            }
            cnt--;
            flag=0;
        }
        else if(cnt==1 && A[i+1].second-A[i].second==1)
        {
            if(flag)
            {
                ans_A[cnt].first=A[tmp].first;
                ans_A[cnt].second=A[tmp].second;
            }
            else
            {
                ans_A[cnt].first=A[i].first;
                ans_A[cnt].second=A[i].second;
            }
            cnt--;
            flag=0;
        }
        else if(A[i].second-A[i-1].second>1)
        {
            cnt=5;
            flag=0;
        }
        else
            cnt=5;
        if(!cnt)
            break;
    }
    if(cnt)
    {
        if(flag)
        {
            ans_A[cnt].first=A[tmp].first;
            ans_A[cnt].second=A[tmp].second;
            cnt--;
        }
        else if(A[1].second-A[0].second==1)
        {
            ans_A[cnt].first=A[0].first;
            ans_A[cnt].second=A[0].second;
            cnt--;
        }
    }

    if(!cnt)
        re_brend=5;
    return re_brend;
}

int Straight_B()
{
    int i,cnt=5,tmp_B=arraylength-1,re_brend=-1,flag=0,tmp;
    for(i=arraylength-1;i>0;i--)
    {
        if(B[i].second==B[i-1].second && !flag)
        {
            flag=1;
            tmp=i;
        }
        else if(B[i].second-B[i-1].second==1)
        {
            if(flag)
            {
                ans_B[cnt].first=B[tmp].first;
                ans_B[cnt].second=B[tmp].second;
            }
            else
            {
                ans_B[cnt].first=B[i].first;
                ans_B[cnt].second=B[i].second;
            }
            cnt--;
            flag=0;
        }
        else if(cnt==1 && B[i+1].second-B[i].second==1)
        {
            if(flag)
            {
                ans_B[cnt].first=B[tmp].first;
                ans_B[cnt].second=B[tmp].second;
            }
            else
            {
                ans_B[cnt].first=B[i].first;
                ans_B[cnt].second=B[i].second;
            }
            cnt--;
            flag=0;
        }
        else if(B[i].second-B[i-1].second>1)
        {
            cnt=5;
            flag=0;
        }
        else
            cnt=5;
        if(!cnt)
            break;
    }
    if(cnt)
    {
        if(flag)
        {
            ans_B[cnt].first=B[tmp].first;
            ans_B[cnt].second=B[tmp].second;
            cnt--;
        }
        else if(B[1].second-B[0].second==1)
        {
            ans_B[cnt].first=B[0].first;
            ans_B[cnt].second=B[0].second;
            cnt--;
        }
    }

    if(!cnt)
        re_brend=5;
    return re_brend;
}

void four_of_a_kind_A(int A_max_num)
{
    int i,cnt=1;
    for(i=arraylength-1;i>=0;i--)
        if(A[i].second!=A_max_num)
        {
            ans_A[5].first=A[i].first;
            ans_A[5].second=A[i].second;
            break;
        }
    for(i=0;i<arraylength;i++)
        if(A[i].second==A_max_num)
        {
            ans_A[cnt].first=A[i].first;
            ans_A[cnt].second=A[i].second;
            cnt++;
        }
}

void four_of_a_kind_B(int A_max_num)
{

    int i,cnt=1;
    for(i=arraylength-1;i>=0;i--)
        if(B[i].second!=A_max_num)
        {
            ans_B[5].first=B[i].first;
            ans_B[5].second=B[i].second;
            break;
        }
    for(i=0;i<arraylength;i++)
        if(B[i].second==A_max_num)
        {
            ans_B[cnt].first=B[i].first;
            ans_B[cnt].second=B[i].second;
            cnt++;
        }
}
int three_cards_A(int A_max_pointer,int A_max_num,int A_brend)
{
    int flag=0,i;
    for(int i=1;i<=3;i++)
    {
        ans_A[i].first=A[A_max_pointer-i+1].first;
        ans_A[i].second=A[A_max_pointer-i+1].second;
    }
    //full house
    for(i=arraylength-1;i>0;i--)
        if(A[i].second!=A_max_num && A[i].second==A[i-1].second)
        {
            flag=1;
            ans_A[4].first=A[i].first;
            ans_A[4].second=A[i].second;
            ans_A[5].first=A[i-1].first;
            ans_A[5].second=A[i-1].second;
            break;
        }
    //three of a find
    if(!flag)
    {
        flag=4;
        for(i=arraylength-1;i>0;i--)
            if(A[i].second!=A_max_num)
            {
                ans_A[flag].first=A[i].first;
                ans_A[flag].second=A[i].second;
                flag++;
                if(flag==6)
                {
                    flag=0;
                    break;
                }
            }
    }
    if(flag)
        A_brend=7;
    else if(A_brend<4)
        A_brend=4;
    return A_brend;
}

int three_cards_B(int A_max_pointer,int A_max_num,int B_brend)
{
    int flag=0,i;
    for(int i=1;i<=3;i++)
    {
        ans_B[i].first=B[A_max_pointer-i+1].first;
        ans_B[i].second=B[A_max_pointer-i+1].second;
    }
    //full house
    for(i=arraylength-1;i>0;i--)
        if(B[i].second!=A_max_num && B[i].second==B[i-1].second)
        {
            flag=1;
            ans_B[4].first=B[i].first;
            ans_B[4].second=B[i].second;
            ans_B[5].first=B[i-1].first;
            ans_B[5].second=B[i-1].second;
            break;
        }
    //three of a find
    if(!flag)
    {
        flag=4;
        for(i=arraylength-1;i>0;i--)
            if(B[i].second!=A_max_num)
            {
                ans_B[flag].first=B[i].first;
                ans_B[flag].second=B[i].second;
                flag++;
                if(flag==6)
                {
                    flag=0;
                    break;
                }
            }
    }
    if(flag)
        B_brend=7;
    else if(B_brend<4)
        B_brend=4;
    return B_brend;
}

int pairs_A(int A_max_pointer,int A_max_num,int A_brend)
{
    int flag=0,i;
    for(int i=1;i<=2;i++)
    {
        ans_A[i].first=A[A_max_pointer-i+1].first;
        ans_A[i].second=A[A_max_pointer-i+1].second;
    }
    //find another pair
    for(i=arraylength-1;i>0;i--)
        if(A[i].second!=A_max_num && A[i].second==A[i-1].second)
        {
            flag=1;
            ans_A[3].first=A[i].first;
            ans_A[3].second=A[i].second;
            ans_A[4].first=A[i-1].first;
            ans_A[4].second=A[i-1].second;
            break;
        }
    //put other single cards into the set
    if(flag)
    {
        flag=5;
        for(i=arraylength-1;i>=0;i--)
            if(A[i].second!=A_max_num && A[i].second!=ans_A[4].second)
            {
                ans_A[flag].first=A[i].first;
                ans_A[flag].second=A[i].second;
                flag--;
                if(flag==4)
                    break;
            }
    }
    else if(!flag)
    {
        flag=3;
        for(i=arraylength-1;i>=0;i--)
            if(A[i].second!=A_max_num)
            {
                ans_A[flag].first=A[i].first;
                ans_A[flag].second=A[i].second;
                flag++;
                if(flag==6)
                {
                    flag=0;
                    break;
                }
            }
    }
    if(flag)
        A_brend=3;
    else if(A_brend<2)
        A_brend=2;
    return A_brend;
}

int pairs_B(int A_max_pointer,int A_max_num,int B_brend)
{
    int flag=0,i;
    for(int i=1;i<=2;i++)
    {
        ans_B[i].first=B[A_max_pointer-i+1].first;
        ans_B[i].second=B[A_max_pointer-i+1].second;
    }
    //find another pair
    for(i=arraylength-1;i>0;i--)
        if(B[i].second!=A_max_num && B[i].second==B[i-1].second)
        {
            flag=1;
            ans_B[3].first=B[i].first;
            ans_B[3].second=B[i].second;
            ans_B[4].first=B[i-1].first;
            ans_B[4].second=B[i-1].second;
            break;
        }
    //put other single cards into the set
    if(flag)
    {
        flag=5;
        for(i=arraylength-1;i>=0;i--)
            if(B[i].second!=A_max_num && B[i].second!=ans_B[4].second)
            {
                ans_B[flag].first=B[i].first;
                ans_B[flag].second=B[i].second;
                flag--;
                if(flag==4)
                    break;
            }
    }
    else if(!flag)
    {
        flag=3;
        for(i=arraylength-1;i>=0;i--)
            if(B[i].second!=A_max_num)
            {
                ans_B[flag].first=B[i].first;
                ans_B[flag].second=B[i].second;
                flag++;
                if(flag==6)
                {
                    flag=0;
                    break;
                }
            }
    }
    if(flag)
        B_brend=3;
    else if(B_brend<2)
        B_brend=2;
    return B_brend;
}

void output_ans(int A_brend)
{
    if(A_brend==9)  printf("Straight Flush\n");
    if(A_brend==8)  printf("Four of a Kind\n");
    if(A_brend==7)  printf("Full house\n");
    if(A_brend==6)  printf("Flush\n");
    if(A_brend==5)  printf("Straight\n");
    if(A_brend==4)  printf("Three of a kind\n");
    if(A_brend==3)  printf("Two Pairs\n");
    if(A_brend==2)  printf("One Pair\n");
    if(A_brend==1)  printf("High card\n");
}
int main()
{
    int T,i,flag=0,f=1,cnt,A_brend,B_brend;
    char t[2],in[20];

    scanf("%d",&T);

    while(T--)
    {
        A_brend=-1;
        B_brend=-1;
        if(f)
            fgets(t,2,stdin);
        f=0;

        fgets(in,20,stdin);       //input A & B's cards
        cut(in,0);      //set all cards to A first

        B[0].first=A[2].first;      //distribute the last two cards to b
        B[0].second=A[2].second;    //
        B[1].first=A[3].first;      //
        B[1].second=A[3].second;    //

        fgets(in,20,stdin);         //input global cards
        cut(in,2);        //set cards to A first
        for(i=2;i<arraylength;i++)
        {
            B[i].first=A[i].first;     //set cards to B
            B[i].second=A[i].second;   //A & B's cards are done
        }

        //judge the brend type
        qsort(A,arraylength,sizeof(player),compare);
        qsort(B,arraylength,sizeof(player),compare);

        /*for(i=0;i<arraylength;i++)
            printf("%c%d ",B[i].first,B[i].second);
        printf("\n");*/
        A_brend=StraightFlush_or_Flush_A();
        B_brend=StraightFlush_or_Flush_B();

        qsort(A,arraylength,sizeof(player),compare2);
        qsort(B,arraylength,sizeof(player),compare2);

        /*for(i=0;i<arraylength;i++)
            printf("%c%d ",A[i].first,A[i].second);
        printf("\n");*/


        //straight
        if(A_brend<5)
            A_brend = Straight_A();
        if(B_brend<5)
            B_brend = Straight_B();
        //others
        int A_cnt[15]={0},A_max=-1e9,A_max_pointer,A_max_num;
        int B_cnt[15]={0},B_max=-1e9,B_max_pointer,B_max_num;
        for(i=0;i<arraylength;i++)
        {
            A_cnt[ A[i].second ]++;
            if(A_cnt[ A[i].second ]>=A_max)
            {
                A_max=A_cnt[ A[i].second ];
                A_max_num=A[i].second;
                A_max_pointer=i;
            }
        }
        for(i=0;i<arraylength;i++)
        {
            B_cnt[ B[i].second ]++;
            if(B_cnt[ B[i].second ]>=B_max)
            {
                B_max=B_cnt[ B[i].second ];
                B_max_num=B[i].second;
                B_max_pointer=i;
            }
        }

        if(A_max==4 && A_brend<8)
        {
            A_brend=8;
            four_of_a_kind_A(A_max_num);
        }
        //full house , three of a find
        else if(A_max==3 && A_brend<7)
            A_brend = three_cards_A(A_max_pointer,A_max_num,A_brend);
        //pairs
        else if(A_max==2 &&A_brend<3)
            A_brend = pairs_A(A_max_pointer,A_max_num,A_brend);
        //hard card
        else if(A_brend<1)
        {
            A_brend=1;
            for(int i=1;i<=5;i++)
            {
                ans_A[i].first=A[arraylength-i].first;
                ans_A[i].second=A[arraylength-i].second;
            }
        }

        if(B_max==4 && B_brend<8)
        {
            B_brend=8;
            four_of_a_kind_B(B_max_num);
        }
        //full house , three of a find
        else if(B_max==3 && B_brend<7)
            B_brend = three_cards_B(B_max_pointer,B_max_num,B_brend);
        //pairs
        else if(B_max==2 &&B_brend<3)
            B_brend = pairs_B(B_max_pointer,B_max_num,B_brend);
        //hard card
        else if(B_brend<1)
        {
            B_brend=1;
            for(int i=1;i<=5;i++)
            {
                ans_B[i].first=B[arraylength-i].first;
                ans_B[i].second=B[arraylength-i].second;
            }
        }

        output_ans(A_brend);
        output_ans(B_brend);

        /*for(i=1;i<=5;i++)
            printf("%c%d ",ans_A[i].first,ans_A[i].second);
        printf("\n");
        for(i=1;i<=5;i++)
            printf("%c%d ",ans_B[i].first,ans_B[i].second);
        printf("\n");*/

        if(A_brend>B_brend)
            printf("Awin");
        else if(A_brend<B_brend)
            printf("Bwin");
        else if(A_brend==B_brend)
        {
            if(A_brend==9)
            {
                if(ans_A[5].second>ans_B[5].second)
                    printf("Awin");
                else if(ans_A[5].second<ans_B[5].second)
                    printf("Bwin");
                else
                    if(ans_A[5].first>ans_B[5].first)
                        printf("Awin");
                    else if(ans_A[5].first<ans_B[5].first)
                        printf("Bwin");
                    else
                        printf("Draw");
            }
            else if(A_brend==8)
            {
                if(ans_A[1].second>ans_B[1].second)
                    printf("Awin");
                else if(ans_A[1].second<ans_B[1].second)
                    printf("Bwin");
                else
                    if(ans_A[5].second>ans_B[5].second)
                        printf("Awin");
                    else if(ans_A[5].second<ans_B[5].second)
                        printf("Bwin");
                    else
                        if(ans_A[5].first>ans_B[5].first)
                            printf("Awin");
                        else if(ans_A[5].first<ans_B[5].first)
                            printf("Bwin");
                        else
                            printf("Draw");
            }
            else if(A_brend==7)
            {
                flag=0;
                for(i=1;i<=3;i++)
                {
                    if(ans_A[i].second>ans_B[i].second)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].second<ans_B[i].second)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    for(i=1;i<=3;i++)
                    {
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    for(i=4;i<=5;i++)
                    {
                        if(ans_A[i].second>ans_B[i].second)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].second<ans_B[i].second)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    for(i=4;i<=5;i++)
                    {
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    printf("Draw");
            }
            else if(A_brend==6)
            {
                flag=0;
                for(i=5;i>=1;i--)
                    if(ans_A[i].second>ans_B[i].second)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].second<ans_B[i].second)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                if(!flag)
                    if(ans_A[5].first>ans_B[5].first)
                    {
                        printf("Awin");
                        flag=1;
                    }
                    else if(ans_A[5].first<ans_B[5].first)
                    {
                        printf("Bwin");
                        flag=1;
                    }
                if(!flag)
                    printf("Draw");
            }
            else if(A_brend==5)
            {
                if(ans_A[5].second>ans_B[5].second)
                    printf("Awin");
                else if(ans_A[5].second<ans_B[5].second)
                    printf("Bwin");
                else
                    if(ans_A[5].first>ans_B[5].first)
                        printf("Awin");
                    else if(ans_A[5].first<ans_B[5].first)
                        printf("Bwin");
                    else
                        printf("Draw");
            }
            else if(A_brend==4)
            {
                flag=0;
                for(i=1;i<=3;i++)
                    if(ans_A[i].second>ans_B[i].second)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].second<ans_B[i].second)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                if(!flag)
                    for(i=1;i<=3;i++)
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                if(!flag)
                    printf("Draw");
            }
            else if(A_brend==3)
            {
                flag=0;
                for(i=1;i<=2;i++)
                {
                    if(ans_A[i].second>ans_B[i].second)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].second<ans_B[i].second)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    for(i=1;i<=2;i++)
                    {
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    for(i=3;i<=4;i++)
                    {
                        if(ans_A[i].second>ans_B[i].second)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].second<ans_B[i].second)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    for(i=3;i<=4;i++)
                    {
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                    }
                if(!flag)
                    printf("Draw");
            }
            else if(A_brend==2)
            {
                flag=0;
                for(i=1;i<=2;i++)
                    if(ans_A[i].second>ans_B[i].second)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].second<ans_B[i].second)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                if(!flag)
                    for(i=1;i<=2;i++)
                        if(ans_A[i].first>ans_B[i].first)
                        {
                            printf("Awin");
                            flag=1;
                            break;
                        }
                        else if(ans_A[i].first<ans_B[i].first)
                        {
                            printf("Bwin");
                            flag=1;
                            break;
                        }
                if(!flag)
                    printf("Draw");
            }
            else if(A_brend==1)
            {
                flag=0;
                for(i=1;i<=5;i++)
                    if(ans_A[i].second>ans_B[i].second)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].second<ans_B[i].second)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].first>ans_B[i].first)
                    {
                        printf("Awin");
                        flag=1;
                        break;
                    }
                    else if(ans_A[i].first<ans_B[i].first)
                    {
                        printf("Bwin");
                        flag=1;
                        break;
                    }
                if(!flag)
                    printf("Draw");
            }
        }
        if(T)
            printf("\n\n");
    }
    return 0;
}
