#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

using namespace std;

int main_box[5][5];

void right()    //"�k"�ާ@
{
    bool test=1;    //while�j��}��
    int test2=0;    //���եΡA�Y�Ӧ�L�ާ@�h��0
	for(int i=1;i<=4;i++)
    {
	    test=1;
		while(test)
        {
            test2=0;    //��l��
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
                if(!test2&&j==3)    //�Ӧ�w�L�ާ@�A����w�����A���Xwhile�i��U�@�C
                    test=0;
            }
        }
	}
}

void down()    //"�U"�ާ@
{
    bool test=1;    //while�j��}��
    int test2=0;    //���եΡA�Y�Ӧ�L�ާ@�h��0
	for(int j=1;j<=4;j++)
    {
	    test=1;
		while(test)
        {
            test2=0;    //��l��
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
                if(!test2&&i==3)    //�Ӧ�w�L�ާ@�A����w�����A���Xwhile�i��U�@�C
                    test=0;
            }
        }
	}
}

int main()
{
	int x_axis,y_axis,cnt=3,change=1;
	char work,ch;
	//��l�ƩҦ����
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			main_box[i][j]=-1;
	//�_�l�H��
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

	//��X�e��
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
        { // �ھڤ��P���䰵���P�B�z
            case -32: // ��V��B�z
            work=getch(); // ��V�䦳2��char,�Aget��2��char; �n�O�o�ŧichar ch1;
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
            cout<<"�п�J�W�U���k"<<"\n";
    }
		return 0;
}
