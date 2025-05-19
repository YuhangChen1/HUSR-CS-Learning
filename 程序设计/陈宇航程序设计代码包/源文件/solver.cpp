//这个文件是对solver.h中CNF求解器部分的实现 

#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<new>
#include<cassert>
#include<time.h>
#include "solver.h"
using namespace std;

int random=1;//如果random==0，会使用“倾向”求解策略，否则会使用“随机”求解策略
//倾向：在分类讨论布尔变元L为真还是为假时，如果一开始的cnf中+L的出现次数比-L多则先讨论真，否则先讨论假
//随机：在分类讨论布尔变元L为真还是为假时，随机先讨论真还是先讨论假 


bool crossCNF::calculate(const char * const filename)
//验证cnf和 res文件是否匹配 
{
	
	int *ans=new int[boolNum+1];//res文件的内容会被写入ans再与cnf进行比较 
	int i,n;
	
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("文件打开失败，不能检验\n");
		delete[] ans;
		return 0;
	}
	fscanf(fp,"%*s%d%*s",&n);
	if(n==0)
	{
		printf("无解，不可验证\n");
		return 0;
	}
	
	printf("res=[");
	for(i=0;i<boolNum;i++)
	{
		fscanf(fp,"%d",&n);
		if(n<0)ans[-n]=0;
		else ans[n]=1;
		printf("%d ",n);
	}
	bool ok;
	crossNode *p;
	printf("]\n检验开始\n");
	for(i=1;i<=clauseNum;i++)//在每个子句中找到第一个为True的文字，找到了，这个子句就算True 
	{
		ok=false;
		p=clauses[i].right;
		while(p)
		{
			n=p->Bool;
			printf("%d ",n);
			if(n<0 && ans[-n]==0  || n>0 && ans[n]==1)
			{
				printf("True");
				ok=true;
				break;
			}
			
			
			p=p->right;
		}
		printf("\n");
		if(!ok)
		{
			printf("clause:False");//如果发现哪个子句为False，则整个cnf也就为False 
			fclose(fp);
			delete[] ans;
			return false;
		}
	}
	
	
	delete[] ans;
	fclose(fp);
	return true;
}

int crossCNF::changeBool(int x)
//把负数翻译成一种比较大的正数的函数，以便其他函数处理负数文字 
{
	return (x>0)?x:(2*boolNum+1+x);
}


bool crossCNF::solve(const char* const filename,bool display)
//名义解，主要工作是为innerSolve函数创造环境，把结果写成文件什么的 
{
	
	FILE *fp=NULL;
	if(filename)fp=fopen(filename,"w");
	if(random)printf("当前求解策略：随机\n");       
	else printf("当前求解策略：倾向\n");
	
	
	clock_t start_time=clock();//开始计时 
	bool ans=innerSolve();
	clock_t end_time=clock();//结束计时 
	double delta_time=(double)(end_time-start_time)/CLOCKS_PER_SEC*1000;
	if(ans)
	{
		//有解 
		if(display){
//		printf("开始时%fms\n",start_time);
//		printf("结束时%fms\n",end_time);
		printf("有解 耗时%fms\n",delta_time);
	}
		hypo[0]=TRUE;
		if(fp)
		{
			fprintf(fp,"s 1\nv ");
		
			for(int i=1;i<=boolNum;i++)
			{
				if(hypo[i]==TRUE)fprintf(fp,"%d ",i);
				else if(hypo[i]==FALSE)fprintf(fp,"-%d ",i);
				else fprintf(fp,"-%d ",i);
			}
			
			fprintf(fp,"\nt %d",delta_time);
		}
			
		
	}
	else
	{
		//无解
		if(display)printf("无解 耗时%f\n",delta_time);
		hypo[0]=FALSE;
		if(fp)fprintf(fp,"s 0\n");
		
	}
	fclose(fp);
	
	
	
	return ans;

}

int crossCNF::believe(int L)
//相信L==true，这个函数会和innerSolve相互调用 
{
	
	//在hypothesis中注册结果 
	if(L>0)hypo[L]=TRUE;
	else hypo[-L]=FALSE;
	//设置“被删除”栈 
	crossNode *DeleteNodesHead=NULL;
	//设置临时指针变量 
	crossNode *p,*q; 
	int i,target;
	int startNum=remainClauseNum;
	
	//删去所有含L的子句 
	for(q=bools[changeBool(L)].down;q;q=q->down)
	{
		
		if(q->del)continue;
		target=q->Clause;
		sum[target]++;
		remainClauseNum--;
		for(p=&clauses[target];p;p=p->right)
		{
			if(p->del)continue;
			p->del=true;      // 已经被删除了 
			
			//把p加入DeleteNodes栈 
			p->next=DeleteNodesHead;  
			DeleteNodesHead=p;
			sum[target]--;
		}
	}
	
	//如果导致剩余子句数量为0 ,就认为这是真解 
	if(remainClauseNum==0)return 1;
	//需要删去所有子句中的-L 
	for(p=bools[changeBool(-L)].down;p;p=p->down)
	{
		if(p->del)continue;
		p->del=true;
		p->next=DeleteNodesHead;
		DeleteNodesHead=p;
		sum[p->Clause]--;
		// 删除多了怎么办 
		//可以在这里检查空子句
		if(sum[p->Clause]==0)
		{
			restore(L,startNum,DeleteNodesHead);
			return 0;
		}
		if(sum[p->Clause]==1)single.push(p->Clause);//如果删出了单子句，就把它加到“单子句”栈中去 
	}
	if(innerSolve())return 1;
	restore(L,startNum,DeleteNodesHead);
	return 0;
}
	
	
void crossCNF::restore(int L,int startNum,crossNode *Head)
//把believe中做出的修改复原 
{
	
	hypo[abs(L)]=UNSURE;
	while(Head)//复原一些结点 
	{
		Head->del=false;
		sum[Head->Clause]++; 
		Head=Head->next;
	}
	remainClauseNum=startNum;
}

int crossCNF::innerSolve()
//实际解，会和believe相互调用 
{
	int i,L;
	crossNode *p;
	while(!single.empty())//试图从“单子句”栈中获得单子句 
	{
		L=single.pop();
		if(!clauses[L].del && sum[L]==1)
		{
			p=clauses[L].right;
			while(p->del)p=p->right;
			return believe(p->Bool);
		}
	}
	
	//选取“第一行第一个” 文字进行分类讨论 ， 这个策略 一般是最好的 
	
	for(i=1;i<=clauseNum;i++)
	{
		if(sum[i]==0) continue;   // 还剩余的文字为0 
		p=clauses[i].right;
		while(p && p->del)p=p->right;
		break;
	}
	L=abs(p->Bool);    // 转化为正数 
	
	//开始分类讨论，首先要决定先考虑正的还是先考虑负的 
	if(random)L*=2*(rand()%2)-1;//随机化选取策略 
	else L*=tendency[L];//倾向选取策略 
	
	if(believe(L))return 1;
	return believe(-L);
	
	
}


