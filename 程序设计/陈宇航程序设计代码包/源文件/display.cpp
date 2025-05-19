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
//���������������ѡ�ѡ��Χ��[stt,end]
//���˵������óɺ��������Ա����ظ��ļ�������Ƿ���ȷ
//�Է���ֵ����ʽ������ 
//����ַ���text�������Ļ�ϣ�����ʾ�û����� 
{
	
	if(end<stt)throw runtime_error("in inputOrder():end<stt\n");//������������ʱ�������汨���϶��Ǵ������������������ 
	int i,ans=-1;
	/*
	i:ѭ������
	ans:�����ص�ֵ 
	
	*/ 
	char s[1000];//�����һ�У�Ӧ��û���˻�һ�д�1000���ַ��� 
	bool ok=false;//���ڱ�������Ƿ�Ϸ��� 
	if(text)printf("%s",text);//�����ʾ���� 
	while(1)//��ѭ����������Ϸ����������룬�����ٴ�ѭ�� 
	{
		fgets(s,sizeof(s),stdin);//����ȫ�ء�����Ļ�϶���һ���ַ��� 
		ok=true;
		
		for(i=0;s[i]!='\n';i++)//��������Ƿ��з������ַ� 
		{
			if(s[i]<'0' || s[i]>'9')
			{
				printf("���뺬�з������ַ�(%c,%d)��������\n",s[i],s[i]);
				ok=false;
				break;//����forѭ�� 
			}
		}
		s[i]='\0';//����ַ�����ĩβ 
		if(ok==false)continue;
		if(strlen(s)==0)continue;//����Ϊ��Ӧ���û�����һ�����е���� 

		ans=atoi(s);// atoi:���ַ�����ʽ������ת��Ϊint 
		if(ans<stt || ans>end)// �ж��Ƿ񳬳���Χ 
		{
			printf("���볬����Χ��������\n");
			ok=false;
			continue;
		} 
		return ans;//��δ������Χ������
	}
	
	
	
}

void useDPLL()
//�˺���������ʾdpllģ��
{
	srand(clock());
	
	char filename[500];//cnf�ļ��� 
	char filename2[500];//res�ļ��� 
	crossCNF *cnf=NULL;//������cnf���� 
	int choice;//ѡ�� 
	FILE *fp=NULL;//�����ļ�ָ�� 
	bool solved=false;//��ʾ��ǰcnf�Ƿ񱻽�����������cnf�������ݽṹ�ᱻ�ƻ��������ٽ⣬�ٽ���Ҫ���´��ļ��ж�ȡ 
	while(1)//��ѭ�� 
	{
		system("cls");//���� 
		choice=inputOrder(0,4,
		"||^^^^^^^^^^^^^^^^^^^^^^^||\n"
		"|| ѡ�������            ||\n"
		"|| ��1��.cnf�Ķ�ȡ��洢 || \n"
		"|| ��2��.����ָ����cnf   ||\n"
		"|| ��3��.������        ||\n"
		"||  (0) .�˳�            ||\n"
		"||^^^^^^^^^^^^^^^^^^^^^^^||\n");
		
		switch(choice)
		{
			case 0:{//�˳� 
				if(cnf!=NULL)delete cnf;//�ͷ�cnf 
				return;
			}
			case 1:{//ָ��cnf 
				//����ָ��cnf�ļ���֮�⣬����黹��Ҫ���³�ʼ����������
				if(cnf!=NULL)
				{
					printf("cnf�Ѿ����壬�����ͷž�cnf\n");
					delete cnf;//�ͷ�cnf 
					cnf=NULL;
					fclose(fp);
					fp=NULL;
				}
				
				
				while(fp==NULL)
				{
					printf("ָ����Ҫ����cnf�ļ�����\n");
					scanf("%s",filename);
					
					fp=fopen(filename,"r");
					if(fp==NULL)printf("���ļ�ʧ�ܣ����ԣ�\n");
				}
				//�����Ѿ����ļ��ɹ�
				cnf=new crossCNF(fp);//���³�ʼ��
				solved=false;
				//Ȼ��Ҫ���¸�ֵfilename2
				strcpy(filename2,filename);
				int i=0;
				while(filename2[i]!='.')i++;
				filename2[i+1]='r';
				filename2[i+2]='e';
				filename2[i+3]='s';
				filename2[i+4]='\0';
				
				printf("����ļ���ָ��Ϊ%s\n",filename2);
				break;
			}
			
			case 2:{//�����ָ����cnf 
				if(cnf==NULL)
				{
					printf("��δָ��cnf!\n");
					break;
				}
				if(solved)
				{
					printf("���cnf�Ѿ�������� ���ݽṹ���ƻ��������³�ʼ����\n");
					break;
				}
				
				cnf->solve(filename2,true);
				solved=true;
				printf("������Ѿ���д��%s\n",filename2);
				break;
			}
			
			case 3:{//��֤����ʾ  
				if(cnf==NULL)
				{
					printf("��δָ��cnf!\n");
					break;
				}
				if(solved==false)
				{
					printf("���cnf��δ��������\n");
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
//�˺�������ʹ�÷�������ģ��
{
	Hanidoku hanidoku,*final,*temp;
	int choice;
	hanidoku.generate_cnf("temp\\empty.cnf");
	
	
	int temp1=1;
	while(1)//��ѭ�� 
	{
		system("cls");
		hanidoku.print();
		choice=inputOrder(0,4,
		"||^^^^^^^^^^^^^^^^^^^^^||\n"
		"|| 1.��������          ||\n"
		"|| 2.�����������      ||\n"
		"|| 3.��⵱ǰ����      ||\n"
		"|| 4.�ж������Ƿ����  ||\n"
		"|| 0.�˳�              ||\n"
		"||^^^^^^^^^^^^^^^^^^^^^||\n");
		switch(choice)
		{
			case 0:{//�˳� 
				 
				return;
			}
			case 1:{//�������� 
				int subchoice=inputOrder(1,2,"���ɿ�����(1)��������ʾ����������Ŀ(2)��\n");
				if(subchoice==1)new (&hanidoku)Hanidoku;//������������
				else 
				{
					int ssc=inputOrder(0,81,"��������Ҫ����ʾ���ĸ���(0<=n<=81)��\n");
					if(ssc)printf("���Եȣ���Ҫ��ʮ���ʱ������һ���н������...\n");
					random=1;
					temp1=clock()%9;
					hanidoku.randomGenerateshow(81-ssc,temp1);
					random=0;
				}
				break;
			}
			
			case 2:{//�������ģʽ 
				
				int line,row,content;
				while(1)
				{
					system("cls");
					hanidoku.print();
					printf("������������������������ݣ���������0�˳�\n�����0��Ϊ�Ƴ��������ݣ�\n");
					
					scanf("%d",&line);
					if(line==0)break;
					scanf("%d%d",&row,&content);
					if(hanidoku.legal(line,row) && content>=0 && content<=9)
					{
						hanidoku.cell(line,row)=content;
					}
					else
					{
						printf("���ݳ�����Χ��������\n");
						system("pause");
					}
					
				}
				break;
			}
			
			case 3:{//��ⳡ�ϸ�� 
				printf("��������cnf...\n");
				hanidoku.generate_cnf("temp\\tempCNF.cnf");
				printf("���ڽ���cnf...\n");
				crossCNF tempCNF("temp\\tempCNF.cnf");
				printf("�������...\n");
//				bool ans=tempCNF.solve("temp\\tempRES.res",false);
				int ans2=hanidoku.oioi();
//				printf("%d",ans2);
				if(ans2==0)
				{
					printf("�Ѿ���������Ľ⣡\n ");
//					hanidoku.load("temp\\tempRES.res");
				     hanidoku.checkkk(temp1);
				}
				else 
				 {
				 	printf("\n");
//				 	hanidoku.print();
				 	printf("û����������Ľ⣡Ҳ��֮ǰ��ģ���Ǵ���ģ�\n");
				 } 
				break;
			}
			
			case 4:{//�ж���Ϸ�ܷ���� 
				if(hanidoku.content_num()<61)
				{
					printf("����δ������\n");
					break;
				}
				printf("��������cnf...\n");
				hanidoku.generate_cnf("temp\\tempCNF.cnf");
				printf("���ڽ���cnf...\n");
				crossCNF tempCNF("temp\\tempCNF.cnf");
				printf("�������...\n");
				bool ans=tempCNF.solve("temp\\tempRES.res",false);
				if(hanidoku.dono())printf("��������ɣ�\n");
				else printf("����������\n");
				
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
			"|| ѡ���ܣ�            ||\n"
			"|| 1.SAT���  ģ��       ||\n"
			"|| 2.X-Sudoku ģ��       ||\n"
			"|| 0.�˳�                ||\n"
			"||^^^^^^^^^^^^^^^^^^^^^^^||\n"
			);
	
		switch(choice)
		{
			case 0:{
				return 0;//��ʱ�˳����ǽ����������� 
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




