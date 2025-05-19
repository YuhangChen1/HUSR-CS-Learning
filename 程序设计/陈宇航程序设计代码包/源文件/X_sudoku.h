
#include<cstdio>
#include<cstring>
#include<stdexcept>
#include<iostream>
#include<cmath> 

using namespace std;


class Hanidoku//��ʾһ���������� 
{
	public:
		//����ÿ�������������ͷ����������
		Hanidoku();//���ɿ����� 
		void load(const char* const filename); //��res�ļ��ж�ȡ 
		int& cell(int x,int y);//�Լ��ĵ�x�е�y��������ӣ���ʵ������ 
		bool legal(int x,int y);//һ�������Ƿ�Ϸ� 
		void print();//��ӡ 
		void generate_cnf(const char* const filename);//���Ϊcnf 
		int content_num();//�Լ��ж��ٸ����ӱ����� 
		void randomGenerate(int n);// �������������Ŀ��n����ʾ�������� 
		void randomGenerateshow(int n,int wi); 
		void checkkk(int wi);
		bool dono();
		int oioi();
	private:
		int mymap[9][9];//9*9�ĸ��ӣ����Դ����������� 
};


