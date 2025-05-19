#include<iostream>
#include<stdexcept>
#include<cstdio>
#include<cstdlib>
#include "solver.h"
#include "X_sudoku.h"
#include <ctime> 
#include <vector>
#include <set>
using namespace std;
extern int random;

int inputOrder(int stt,int end,const char* const text=NULL)
//这个函数用来输入选项，选择范围是[stt,end]
//将此单独设置成函数，可以避免重复的检查输入是否正确
//以返回值的形式输出结果 
//会把字符串text输出在屏幕上，以提示用户输入 
{
	
	if(end<stt)throw runtime_error("in inputOrder():end<stt\n");//遇到输入问题时报错。如真报错，肯定是代码问题而非输入问题 
	int i,ans=-1;
	/*
	i:循环变量
	ans:待返回的值 
	
	*/ 
	char s[1000];//输入的一行，应该没有人会一行打1000个字符吧 
	bool ok=false;//用于标记输入是否合法。 
	if(text)printf("%s",text);//输出提示文字 
	while(1)//主循环。如输入合法，返回输入，否则再次循环 
	{
		fgets(s,sizeof(s),stdin);//“安全地”从屏幕上读入一行字符串 
		ok=true;
		
		for(i=0;s[i]!='\n';i++)//检查输入是否含有非数字字符 
		{
			if(s[i]<'0' || s[i]>'9')
			{
				printf("输入含有非数字字符(%c,%d)，请重试\n",s[i],s[i]);
				ok=false;
				break;//跳出for循环 
			}
		}
		s[i]='\0';//标记字符串的末尾 
		if(ok==false)continue;
		if(strlen(s)==0)continue;//这是为了应对用户输入一个空行的情况 

		ans=atoi(s);// atoi:把字符串形式的整数转化为int 
		if(ans<stt || ans>end)// 判断是否超出范围 
		{
			printf("输入超出范围，请重试\n");
			ok=false;
			continue;
		} 
		return ans;//如未超出范围，返回
	}
	
	
	
}

void useDPLL()
//此函数用于演示dpll模块
{
	srand(clock());
	
	char filename[500];//cnf文件名 
	char filename2[500];//res文件名 
	crossCNF *cnf=NULL;//待定的cnf对象 
	int choice;//选项 
	FILE *fp=NULL;//待定文件指针 
	bool solved=false;//表示当前cnf是否被解过。被解过的cnf对象数据结构会被破坏，不能再解，再解需要重新从文件中读取 
	while(1)//主循环 
	{
		system("cls");//清屏 
		choice=inputOrder(0,4,
		"||^^^^^^^^^^^^^^^^^^^^^^^||\n"
		"|| 选择操作：            ||\n"
		"|| （1）.cnf的读取与存储 || \n"
		"|| （2）.解已指定的cnf   ||\n"
		"|| （3）.检验结果        ||\n"
		"||  (0) .退出            ||\n"
		"||^^^^^^^^^^^^^^^^^^^^^^^||\n");
		
		switch(choice)
		{
			case 0:{//退出 
				if(cnf!=NULL)delete cnf;//释放cnf 
				return;
			}
			case 1:{//指定cnf 
				//除了指定cnf文件名之外，这个块还需要重新初始化其他内容
				if(cnf!=NULL)
				{
					printf("cnf已经定义，正在释放旧cnf\n");
					delete cnf;//释放cnf 
					cnf=NULL;
					fclose(fp);
					fp=NULL;
				}
				
				
				while(fp==NULL)
				{
					printf("指定需要求解的cnf文件名：\n");
					scanf("%s",filename);
					
					fp=fopen(filename,"r");
					if(fp==NULL)printf("打开文件失败！重试！\n");
				}
				//现在已经打开文件成功
				cnf=new crossCNF(fp);//重新初始化
				solved=false;
				//然后还要重新赋值filename2
				strcpy(filename2,filename);
				int i=0;
				while(filename2[i]!='.')i++;
				filename2[i+1]='r';
				filename2[i+2]='e';
				filename2[i+3]='s';
				filename2[i+4]='\0';
				
				printf("输出文件被指定为%s\n",filename2);
				break;
			}
			
			case 2:{//求解已指定的cnf 
				if(cnf==NULL)
				{
					printf("还未指定cnf!\n");
					break;
				}
				if(solved)
				{
					printf("这个cnf已经被解过， 数据结构被破坏，请重新初始化！\n");
					break;
				}
				
				cnf->solve(filename2,true);
				solved=true;
				printf("求解结果已经被写入%s\n",filename2);
				break;
			}
			
			case 3:{//验证并显示  
				if(cnf==NULL)
				{
					printf("还未指定cnf!\n");
					break;
				}
				if(solved==false)
				{
					printf("这个cnf还未被求解过！\n");
					break;
				}				 
				cnf->calculate(filename2);
				break;
			}
			
			
		}
		system("pause");
	}
	
	
	
}


void useHanidoku()
//此函数用于使用蜂窝数独模块
{
	Hanidoku hanidoku,*final,*temp;
	int choice;
	hanidoku.generate_cnf("temp\\empty.cnf");
	
	
	int temp1=1;
	while(1)//主循环 
	{
		system("cls");
		hanidoku.print();
		choice=inputOrder(0,4,
		"||^^^^^^^^^^^^^^^^^^^^^||\n"
		"|| 1.生成数独          ||\n"
		"|| 2.进入数独填充      ||\n"
		"|| 3.求解当前数独      ||\n"
		"|| 4.判断数独是否完成  ||\n"
		"|| 0.退出              ||\n"
		"||^^^^^^^^^^^^^^^^^^^^^||\n");
		switch(choice)
		{
			case 0:{//退出 
				 
				return;
			}
			case 1:{//生成数独 
				int subchoice=inputOrder(1,2,"生成空数独(1)还是有提示数的数独题目(2)？\n");
				if(subchoice==1)new (&hanidoku)Hanidoku;//重置数独对象
				else 
				{
					int ssc=inputOrder(0,81,"输入你需要的提示数的个数(0<=n<=81)？\n");
					if(ssc)printf("请稍等，需要几十秒的时间生成一个有解的数独...\n");
					random=1;
					temp1=clock()%9;
					hanidoku.randomGenerateshow(81-ssc,temp1);
					random=0;
				}
				break;
			}
			
			case 2:{//进入操作模式 
				
				int line,row,content;
				while(1)
				{
					system("cls");
					hanidoku.print();
					printf("输入行数，列数，和填充内容，或者输入0退出\n（填充0即为移除格中内容）\n");
					
					scanf("%d",&line);
					if(line==0)break;
					scanf("%d%d",&row,&content);
					if(hanidoku.legal(line,row) && content>=0 && content<=9)
					{
						hanidoku.cell(line,row)=content;
					}
					else
					{
						printf("数据超出范围，请重试\n");
						system("pause");
					}
					
				}
				break;
			}
			
			case 3:{//求解场上格局 
				printf("正在生成cnf...\n");
				hanidoku.generate_cnf("temp\\tempCNF.cnf");
				printf("正在解析cnf...\n");
				crossCNF tempCNF("temp\\tempCNF.cnf");
				printf("正在求解...\n");
//				bool ans=tempCNF.solve("temp\\tempRES.res",false);
				int ans2=hanidoku.oioi();
//				printf("%d",ans2);
				if(ans2==0)
				{
					printf("已经求得数独的解！\n ");
//					hanidoku.load("temp\\tempRES.res");
				     hanidoku.checkkk(temp1);
				}
				else 
				 {
				 	printf("\n");
//				 	hanidoku.print();
				 	printf("没有求得数独的解！也许之前的模板是错误的！\n");
				 } 
				break;
			}
			
			case 4:{//判断游戏能否结束 
				if(hanidoku.content_num()<61)
				{
					printf("场上未填满！\n");
					break;
				}
				printf("正在生成cnf...\n");
				hanidoku.generate_cnf("temp\\tempCNF.cnf");
				printf("正在解析cnf...\n");
				crossCNF tempCNF("temp\\tempCNF.cnf");
				printf("正在求解...\n");
				bool ans=tempCNF.solve("temp\\tempRES.res",false);
				if(hanidoku.dono())printf("数独已完成！\n");
				else printf("数独不合理！\n");
				
				break;
			}
		}
		system("pause");
	}
}




int main()
{
	int choice;
	while(1)
	{
		system("cls");
		choice=inputOrder(0,2,
			"||^^^^^^^^^^^^^^^^^^^^^^^||\n"
			"|| 选择功能：            ||\n"
			"|| 1.SAT求解  模块       ||\n"
			"|| 2.X-Sudoku 模块       ||\n"
			"|| 0.退出                ||\n"
			"||^^^^^^^^^^^^^^^^^^^^^^^||\n"
			);
	
		switch(choice)
		{
			case 0:{
				return 0;//此时退出就是结束整个程序 
			}
			case 1:{
				useDPLL();
				break;
			}
			
			case 2:{
				useHanidoku();
				break;
			}
		}
		
	}
	
	
}




