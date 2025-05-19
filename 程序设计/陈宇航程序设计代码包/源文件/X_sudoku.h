
#include<cstdio>
#include<cstring>
#include<stdexcept>
#include<iostream>
#include<cmath> 

using namespace std;


class Hanidoku//表示一套数独布局 
{
	public:
		//以下每个方法有数独和蜂窝两种情况
		Hanidoku();//生成空数独 
		void load(const char* const filename); //从res文件中读取 
		int& cell(int x,int y);//自己的第x行第y个这个格子，其实很冗余 
		bool legal(int x,int y);//一个坐标是否合法 
		void print();//打印 
		void generate_cnf(const char* const filename);//输出为cnf 
		int content_num();//自己有多少个格子被填了 
		void randomGenerate(int n);// 随机生成数独题目，n是提示数的数量 
		void randomGenerateshow(int n,int wi); 
		void checkkk(int wi);
		bool dono();
		int oioi();
	private:
		int mymap[9][9];//9*9的格子，足以存下两种数独 
};


