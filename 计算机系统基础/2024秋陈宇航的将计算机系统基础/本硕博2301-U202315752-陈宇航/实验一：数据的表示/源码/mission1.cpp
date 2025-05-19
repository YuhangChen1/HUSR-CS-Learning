#include<bits/stdc++.h>
#include<windows.h>
using namespace std;


const int N = 5;


struct student {
	char name[8];
	short age;
	float score;//
	char remark[196];//��ע��Ϣ
};


student new_s[N];

//����ѹ������ ����ѹ����ĳ���
int pack_student_bytebybyte(student* s, int sno, char* buf);
int pack_student_whole(student* s, int sno, char* buf);




//��ѹ����
int restore_student(char* buf, int len, student* s);


//�������
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
	cout << "�������ǻ����û��ѹ��������" << endl;
	//��ʼ��ӡold_s;
	for (int i = 0; i < N; i++)
	{
		cout << old_s[i].name << ' ' << old_s[i].age << ' ' << old_s[i].score << ' ' << old_s[i].remark << endl;
	}
	cout << "ѹ��ǰ������ݵĴ�СΪ....." << sizeof(old_s) << endl;
	cout << "�����һᰴ���ֽ�ѹ��ǰ����...." << endl;



	//�����ֽڽ���ѹ��

	int len = pack_student_bytebybyte(old_s, 2, message);
	

	cout << "��ʱmessage�ĳ�����:" << len<<endl;

	//һ��һ��ѹ��
	cout << "�����һᰴ���ֽ�ѹ��������...." << endl;
	len += pack_student_whole(&old_s[2], 3, message + len);

	cout << "��ʱmessage�ĳ�����:." << len << endl;


	//��ʼ����洢��Ϣ���message����Ϣ
	cout << "��ʼ����洢��Ϣ���message����Ϣ......" << endl;
	printMessage(message, len);

	//�����ѹmessage�е���Ϣ���ṹ������
	cout << "�����ѹmessage�е���Ϣ���ṹ������..." << endl;
	int num = restore_student(message, len, new_s);


	//��ӡnew_s[n]
	for (int i = 0; i < num; i++)
	{
		cout << new_s[i].name << ' ' << new_s[i].age << ' ' << new_s[i].score << ' ' << new_s[i].remark << endl;
	}

	char* pp = message;
	cout << "������16���Ƶ����ƣ����message�����ǰ20���ֽڵ���Ϣ" << endl;
	for (int i = 0; i < 20; i++)
	{
		printf("%02x ", (unsigned char)(*(pp + i)));
	}
	return 0;

}





int pack_student_bytebybyte(student* s, int sno, char* buf)
{
	//s ��Ҫѹ������ʼ��ַ sno��ѹ������
	//buf��ѹ��֮����׵�ַ ����ѹ��֮����ֽ���
	int cnts = 0;
	int cntname, cntage, cntscore, cntmark;
	int cntbuf = 0;//Ҫ���ص�����
	char*p = (char*)s;
	char* pp = (char*)buf;
	while (cnts < sno)
	{
		//��ȡ����
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
				p += (8 - cntname);//����name����ʣ�µ�û��ʹ�õĿռ�
				pp++;
				break;
			}
		}

		//��ȡ����
		cntage = 0;
		while (cntage < 2)
		{
			*pp = *p;
			cntbuf++;
			cntage++;
			p++;
			pp++;
		}

		//�ڴ���룺short2�� float4�� ÿһ����8�� �������2������
		p += 2;


		//����float ռ4���ֽ�
		cntscore = 0;
		while (cntscore < 4)
		{
			*pp = *p;
			cntbuf++, cntscore++, p++, pp++;
		}



		//��ȡremark����
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
		pp += strlen(ppp[cnts].name) + 1;//С��0
		*((short*)pp) = ppp[cnts].age;
		pp += 2;//��λ
		*((float*)pp) = ppp[cnts].score;
		pp += 4;
		strcpy(pp, ppp[cnts].remark);
		pp += strlen(ppp[cnts].remark) + 1;
		cnts++;
	}
	return pp - buf;
}



//buf�Ǵ洢���׵�ַ��lenΪ����,sΪ���ѹ�����ݵĽṹ������ֵ�ַ�����ؽ�ѹ����
int restore_student(char* buf, int len, student* s)
{
	int cnt=0;//��¼�Ѿ���ѹ������
	char* p = buf;
	student* pp = s;
	while ((p - buf) < len)
	{
		//��ѹ����
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
		cout << p << ' ';//����
		p += strlen(p) + 1;
		cout << *((short*)p) << ' ';
		p += 2;
		cout << *((float*)p) << ' ';
		p += 4;
		cout << p << ' '<<endl;
		p += strlen(p) +1;
	}
}


