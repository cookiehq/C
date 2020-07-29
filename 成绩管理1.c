/*
文本菜单第6版，switch实现多路分支，模块化设计
用char替代int作为输入选项的类型，避免格式异常

2017.9.25
*/

#include <stdio.h>
#define N 38
int  score[N] ={100 , 90 ,80  }; //全局变量
int total , max ,min ;
float average ;

void input() //输入成绩
{
	int i ;

	for ( i = 0 ; i < N ; i++)
	{
		do
		{
			printf("请输入第%d同学的成绩：" , i);
			scanf("%d" , &score[i]);

			if(score[i] < 0 || score[i] > 100)
				printf("成绩越界！" );		
		}while (score[i] < 0 || score[i] > 100);	
	}
}

void output()
{
	int i ;

	for (i = 0 ; i < N ; i++)
		printf("%d\t" , score[i]);

	printf ("\n最高分：%d\n" , max);
	printf ("最低分：%d\n" , min);
	printf ("平均分：%.2f\n" , average);
}

void process()
{
	int i ;

	total = min = max = score [0];

	for ( i = 1 ; i < N ; i++)
	{
		total +=  score [i] ;

		if (score [i] > max)
			max = score [i] ;

		if (score [i] < min)
			min = score [i] ;	
	}
	average =(float) total / N ; //
	printf("统计结束！");
}

void randdata()
{
	int i ;

	srand((unsigned)time(NULL));  //利用时间函数做种子

	for (i = 0 ; i < N ; i++)
	{
		score[i] = 50+ rand() % 51 ; //产生随机数50-100
	}
	printf("产生随机数成绩！");

}

//主函数
main()
{
	char choice;
	void ListMenu(); //函数声明

	while(1)
	{
		system("cls"); // 清屏 clear screen
		ListMenu(); //函数调用
		printf("输入你的选择：");
		//scanf("%c" , &choice);
		choice = getche() ; //输入单个字符，不用回车
		printf("\n");

		switch(choice)
		{
		case '0':
			return;
		case '1':
			input();
			break;
		case '2':
			process();
			break;
		case '3':
			output();
			break;
		case '4':
			randdata();
			break;
		default:
			printf("输入错误！\n");	
		}// end switch
		printf("Press any key to continue.....");
		getch();
	}//end while
	getch();
}

//显示文本菜单
void ListMenu()
{
	printf("  课程菜单\n");
	printf("===========\n");
	printf("1.输入成绩\n");
	printf("2.统计处理\n");
	printf("3.输出\n");
	printf("4.随机成绩\n");
	printf("0. 退出\n");
	printf("===========\n");
}
