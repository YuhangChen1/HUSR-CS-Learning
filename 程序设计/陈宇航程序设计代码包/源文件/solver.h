

#include<cstdio>


using namespace std;
#define MAXN 10000

enum BOOLVALUE {UNSURE, FALSE, TRUE};




struct crossNode
//十字链表节点 
{
	
	int Bool;//表示自己的布尔变元 
	int Clause;//表示自己的子句
	bool del;
	crossNode *up,*down,*right,*left,*next;
	crossNode()
	{
		Bool=0;
		Clause=0;
		up=NULL;
		down=NULL;
		right=NULL;
		left=NULL;
		next=NULL;
		del=false;
	}

};

struct intStack
//int栈，这里使用数组栈 
//这么短的代码就不写cpp文件了 
{
	int S[MAXN];
	int i=0;
	void push(int value)
	{
		S[i++]=value;
	}
	
	int pop()
	{
		//assert(i>0);
		return S[--i];
	}

	bool empty()
	{
		return i==0;
	}

};

class crossCNF
//十字链表cnf 
{
	public:
		
		crossCNF(const char * const filename);//构造函数 
		crossCNF(FILE *fp);//构造函数（文件指针版） 
		~crossCNF();//析构函数 
		bool calculate(const char * const filename);//检验 
		void print(FILE *);//打印 
		bool solve(const char* const filename,bool display);//名义解 
		
	private:
		int boolNum;//布尔变元个数 
		int clauseNum;//子句个数（原来的） 
		int remainClauseNum;//删了一些之后剩下的子句个数 
		int *sum;//每个子句的剩余文字个数 
		int *tendency;//每个文字的“倾向” 
		crossNode *bools;//编号从1开始 
		crossNode *clauses;//编号从1开始 
		BOOLVALUE *hypo;//搜索时使用的“假设” 
		intStack single;//存单子句的栈 
		
		void addNode(int,int);//添加结点，生成cnf对象时要用 
		int changeBool(int);//把[-boolNum,-1]U[1,boolNum]翻译成[1,2*boolNum]的函数 
		int innerSolve();//实际解 
		int believe(int);//“相信”，具体含义请看solver.cpp 
		void restore(int L,int startNum,crossNode *Head);//恢复被believe函数修改过的cnf 
		
};



		

		
		
		
		
	
