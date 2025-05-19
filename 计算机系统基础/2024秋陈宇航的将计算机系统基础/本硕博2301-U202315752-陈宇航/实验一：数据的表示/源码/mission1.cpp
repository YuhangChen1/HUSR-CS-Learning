#include<bits/stdc++.h>
#include<windows.h>
using namespace std;


const int N = 5;


struct student {
	char name[8];
	short age;
	float score;//
	char remark[196];//备注信息
};


student new_s[N];

//两种压缩函数 返回压缩后的长度
int pack_student_bytebybyte(student* s, int sno, char* buf);
int pack_student_whole(student* s, int sno, char* buf);




//解压函数
int restore_student(char* buf, int len, student* s);


//输出函数
void printMessage(char* message, int len);




int main()
{
	char message[500];


	student old_s[N] = {
		{"francis",19,43,"mystery"},
		{"love",1,100,"disappear"},
		{"someone",19,100,"where"},
		{"who",57,99,"donot"},
		{"lost",99,0,"always"}
	};
	cout << "现在我们会输出没有压缩的内容" << endl;
	//开始打印old_s;
	for (int i = 0; i < N; i++)
	{
		cout << old_s[i].name << ' ' << old_s[i].age << ' ' << old_s[i].score << ' ' << old_s[i].remark << endl;
	}
	cout << "压缩前存放数据的大小为....." << sizeof(old_s) << endl;
	cout << "下面我会按照字节压缩前两个...." << endl;



	//按照字节进行压缩

	int len = pack_student_bytebybyte(old_s, 2, message);
	

	cout << "此时message的长度是:" << len<<endl;

	//一条一条压缩
	cout << "下面我会按照字节压缩后三个...." << endl;
	len += pack_student_whole(&old_s[2], 3, message + len);

	cout << "此时message的长度是:." << len << endl;


	//开始输出存储信息后的message的信息
	cout << "开始输出存储信息后的message的信息......" << endl;
	printMessage(message, len);

	//下面解压message中的信息到结构体里面
	cout << "下面解压message中的信息到结构体里面..." << endl;
	int num = restore_student(message, len, new_s);


	//打印new_s[n]
	for (int i = 0; i < num; i++)
	{
		cout << new_s[i].name << ' ' << new_s[i].age << ' ' << new_s[i].score << ' ' << new_s[i].remark << endl;
	}

	char* pp = message;
	cout << "下面以16进制的形势，输出message里面的前20个字节的信息" << endl;
	for (int i = 0; i < 20; i++)
	{
		printf("%02x ", (unsigned char)(*(pp + i)));
	}
	return 0;

}





int pack_student_bytebybyte(student* s, int sno, char* buf)
{
	//s 是要压缩的起始地址 sno是压缩人数
	//buf是压缩之后的首地址 返回压缩之后的字节数
	int cnts = 0;
	int cntname, cntage, cntscore, cntmark;
	int cntbuf = 0;//要返回的数字
	char*p = (char*)s;
	char* pp = (char*)buf;
	while (cnts < sno)
	{
		//读取名字
		cntname = 0;
		while (cntname < 10)
		{
			if (*p)
			{
				*pp = *p;
				cntname++;
				cntbuf++;
				p++;
				pp++;
			}
			else
			{
				*pp = '\0';
				cntbuf++;
				p += (8 - cntname);//跳过name数组剩下的没有使用的空间
				pp++;
				break;
			}
		}

		//读取年龄
		cntage = 0;
		while (cntage < 2)
		{
			*pp = *p;
			cntbuf++;
			cntage++;
			p++;
			pp++;
		}

		//内存对齐：short2个 float4个 每一段是8个 这里会有2个对齐
		p += 2;


		//读入float 占4个字节
		cntscore = 0;
		while (cntscore < 4)
		{
			*pp = *p;
			cntbuf++, cntscore++, p++, pp++;
		}



		//读取remark数组
		cntmark = 0;
		while (cntmark < 20)
		{
			if (*p)
			{
				*pp = *p;
				cntbuf++, cntmark++, p++, pp++;
			}
			else
			{
				*pp = 0;
				cntbuf++;
				pp++;
				p += (200 - cntmark);
				break;
			}
			cnts++;
		}
	}
	return cntbuf;
}


int pack_student_whole(student* s, int sno, char* buf)
{
	int cnts = 0;
	char* p = (char*)s;
	char* pp = buf;
	student* ppp = s;
	while (cnts < sno)
	{
		strcpy(pp, ppp[cnts].name);
		pp += strlen(ppp[cnts].name) + 1;//小心0
		*((short*)pp) = ppp[cnts].age;
		pp += 2;//补位
		*((float*)pp) = ppp[cnts].score;
		pp += 4;
		strcpy(pp, ppp[cnts].remark);
		pp += strlen(ppp[cnts].remark) + 1;
		cnts++;
	}
	return pp - buf;
}



//buf是存储的首地址，len为长度,s为存放压缩数据的结构数组的手地址，返回解压人数
int restore_student(char* buf, int len, student* s)
{
	int cnt=0;//记录已经解压的人数
	char* p = buf;
	student* pp = s;
	while ((p - buf) < len)
	{
		//解压名字
		strcpy(pp[cnt].name, p);
		p += strlen(pp[cnt].name) + 1;
		pp[cnt].age = *((short*)p);
		p += 2;
		pp[cnt].score = *((float*)p);
		p += 4;
		strcpy(pp[cnt].remark, p);
		p += strlen(pp[cnt].remark) + 1;
		cnt++;
	}
	return cnt;
}



void printMessage(char* message, int len)
{
	int cnt = 0;
	char* p = message;
	while (p - message < len)
	{
		cout << p << ' ';//名字
		p += strlen(p) + 1;
		cout << *((short*)p) << ' ';
		p += 2;
		cout << *((float*)p) << ' ';
		p += 4;
		cout << p << ' '<<endl;
		p += strlen(p) +1;
	}
}


