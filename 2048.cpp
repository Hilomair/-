#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

using namespace std;

int main_box[5][5];

void right()    //"右"操作
{
    bool test=1;    //while迴圈開關
    int test2=0;    //測試用，若該行無操作則為0
	for(int i=1;i<=4;i++)
    {
	    test=1;
		while(test)
        {
            test2=0;    //初始化
            for(int j=1;j<=3;j++)
            {
                if( ( main_box[i][j]!=(-1) )&&( main_box[i][j+1]==(-1) ) )
                {
                    swap(main_box[i][j],main_box[i][j+1]);
                    test2++;
                }
                else if((main_box[i][j]==main_box[i][j+1])&&(main_box[i][j]!=-1))
                {
                    main_box[i][j+1]*=2;
                    main_box[i][j]=-1;
                    test2++;
                }
                if(!test2&&j==3)    //該行已無操作，此行已結束，跳出while進行下一列
                    test=0;
            }
        }
	}
}

void down()    //"下"操作
{
    bool test=1;    //while迴圈開關
    int test2=0;    //測試用，若該行無操作則為0
	for(int j=1;j<=4;j++)
    {
	    test=1;
		while(test)
        {
            test2=0;    //初始化
            for(int i=1;i<=3;i++)
            {
                if( ( main_box[i][j]!=(-1) )&&( main_box[i+1][j]==(-1) ) )
                {
                    swap(main_box[i][j],main_box[i+1][j]);
                    test2++;
                }
                else if((main_box[i][j]==main_box[i+1][j])&&(main_box[i][j]!=-1))
                {
                    main_box[i+1][j]*=2;
                    main_box[i][j]=-1;
                    test2++;
                }
                if(!test2&&i==3)    //該行已無操作，此行已結束，跳出while進行下一列
                    test=0;
            }
        }
	}
}

int main()
{
	int x_axis,y_axis,cnt=3,change=1;
	char work,ch;
	//初始化所有方格
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			main_box[i][j]=-1;
	//起始隨機
	srand(time(NULL));
	while(cnt)
	{
		x_axis=(rand()%5)+1;
		y_axis=(rand()%5)+1;
		if(main_box[x_axis][y_axis] == (-1))
		{
			main_box[x_axis][y_axis] = 2;
			cnt--;
		}
	}

	//輸出畫面
	while(1)
    {
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(main_box[i][j]!=-1)
                    cout<<main_box[i][j];
                else
                    cout<<"0";
            }
            cout<<"\n";
        }
        ch=getch();
        switch(ch)
        { // 根據不同按鍵做不同處理
            case -32: // 方向鍵處理
            work=getch(); // 方向鍵有2個char,再get第2個char; 要記得宣告char ch1;
            switch(work)
            {
                case 72: // Up
                break;
                case 75: // Left
                break;
                case 77: // Right
                right();break;
                case 80: // Down
                down();break;
            }
            default:
            change=0;
            break;
        }
        while(change)
        {
            x_axis=(rand()%5)+1;
            y_axis=(rand()%5)+1;
            if(main_box[x_axis][y_axis] == (-1))
            {
                main_box[x_axis][y_axis] = 2;
                break;
            }
        }
        system("CLS");
        if(!change)
            cout<<"請輸入上下左右"<<"\n";
    }
		return 0;
}
