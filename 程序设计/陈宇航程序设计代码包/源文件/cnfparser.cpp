#include<new>
#include "solver.h"
crossCNF::crossCNF(FILE *fp)//构造函数，可根据fp构造CNF对象 
{
	char get;
	
	//跳过注释：		
	while(1)
	{
		get=fgetc(fp);
		if(get=='c')while(fgetc(fp)!='\n'); // 跳过注释 
		else break;
	}
	
	//理论上，现在get=='p'
	//取元数据 
	fscanf(fp,"%*s%d%d",&boolNum,&clauseNum);
	
	remainClauseNum=clauseNum;
	
	
	//开辟数据空间 
	clauses = new crossNode[clauseNum+1];
	bools = new crossNode[2*boolNum+2];
	hypo = new BOOLVALUE[boolNum+1];
	sum = new int[clauseNum+1];
	
	
	int i,nowClause=1,temp;
	for(i=0;i<=clauseNum;i++)clauses[i].Bool=0;
	for(i=0;i<=boolNum;i++)hypo[i]=UNSURE;
	for(i=0;i<2*boolNum+2;i++)bools[i].Bool=0;
	for(i=0;i<=clauseNum;i++)sum[i]=0;
	//逐个存储
	while(nowClause<=clauseNum)
	{
		fscanf(fp,"%d",&temp);
		if(temp==0)nowClause++;
		else addNode(nowClause,temp);// 在此处添加十字链表结点 
	}
	fclose(fp);
	
	
	
	
	//初始化“单子句”栈 
	for(i=1;i<=clauseNum;i++)if(sum[i]==1)single.push(i);
	
	//初始化“倾向” 
	tendency=new int[boolNum+1];
	int posi,nega;
	crossNode *p;
	for(i=1;i<=boolNum;i++)
	{
		posi=0;
		nega=0;
		// 记录正数出现多还是负数出现多 
		for(p=bools[i].down;p;p=p->down)posi++;
		for(p=bools[changeBool(-i)].down;p;p=p->down)nega++;
		if(posi>=nega)tendency[i]=1;
		else tendency[i]=-1;
	}

	return ;
}


crossCNF::crossCNF(const char * const filename)//构造函数，根据文件名构造CNF对象 
{
	FILE *fp=fopen(filename,"r");
	new (this)crossCNF(fp);
	fclose(fp);
}

crossCNF::~crossCNF()//析构函数 
{
	crossNode *p,*q;
	int i;
	//逐行删除 
	for(i=1;i<=clauseNum;i++)
	{
		p=clauses[i].right;
		while(p)
		{
			q=p->right;
			delete p;
			p=q;
		}
	}
	delete[] bools,clauses,hypo,sum,tendency;//删去手动分配的数组空间 
}
	
	
void crossCNF::print(FILE *fp=stdout)
{
	crossNode *p;
	for(int i=1;i<=clauseNum;i++)
	{
		if(clauses[i].del)continue;
		fprintf(fp,"%d:",i);
		for(p=clauses[i].right;p!=NULL;p=p->right)
		{
			if(p->del)continue;
			fprintf(fp,"%d ",p->Bool);
		}
		fprintf(fp,"\n");
	}
}



void crossCNF::addNode(int Clause,int Bool)
{
	crossNode *p=new crossNode(),*p1,*p2;
	p->Bool=Bool;
	p->Clause=Clause;	
	Bool=changeBool(Bool);//正负数坐标转化为物理坐标 
	p1=&clauses[Clause];
	p2=&bools[Bool];
	
	while(p1->right!=NULL && changeBool(p1->right->Bool)<Bool)p1=p1->right;
	while(p2->down!=NULL && p2->down->Clause<Clause)p2=p2->down;
	if(p1->right)p1->right->left=p;
	p->right=p1->right;
	p1->right=p;
	p->left=p1;
	
	if(p2->down)p2->down->up=p;
	p->down=p2->down;
	p2->down=p;
	p->up=p2;
	
	sum[Clause]++;

}
