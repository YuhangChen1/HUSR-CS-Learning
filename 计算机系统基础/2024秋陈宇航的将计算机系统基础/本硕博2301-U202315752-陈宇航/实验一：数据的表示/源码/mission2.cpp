
#include<bits/stdc++.h>

using namespace std;

//1.����x�ľ���ֵ
int absVal(int x);

//��������1
int absVal_standard(int x) { return (x < 0) ? -x : x; }

//2.�����ø��ţ�����-x
int netgate(int x);
//��������2
int netgate_standard(int x) { return -x; }

//3.(3)��ʹ�� ~ �� |��ʵ�� &
int bitAnd(int x, int y);
//��������3
int bitAnd_standard(int x, int y) { return x & y; }


//4.��ʹ�� ~�� & ��ʵ��|
int bitOr(int x, int y);
//��������4
int bitOr_standard(int x, int y) { return x | y; }

//5.(5)��ʹ�� ~ �� &��ʵ�� ^
int bitXor(int x, int y);
//��������5
int bitXor_standard(int x, int y) { return x ^ y; }


//6.�ж�x�Ƿ�Ϊ������������7FFFFFFF��
int isTmax(int x);
//�жϺ���6
int isTmax_standard(int x) { return x == 0x7FFFFFFF; }

//7.ͳ��x�Ķ����Ʊ�ʾ�� 1 �ĸ���
int bitCount(int x);
//�жϺ���7
int bitCount_standard(int x)
{
    int a = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((x >> i) & 1))
        {
            a++;
        }
    }
    return a;
}


//8.������lowbit��highbitȫΪ1 ����ȫΪ0����
int bitMask(int highbit, int lowbit);
int bitMask_standard(int highbit, int lowbit)
{
    int ans = 0;
    for (int i = lowbit; i <= highbit; i++)
    {
        ans += (1 << (i));
    }
    return ans;
}


//9.��x+y����������ʱ�򷵻�1�����򷵻�0
int addOK(int x, int y);
int addOK_standard(int x, int y)
{
    long long lsum = (long long)(x + y);
    return !(lsum == (int)lsum);
}


//10.��x�ĵ�n���ֽ����m���ֽڽ��������ؽ�����Ľ���� n��m��ȡֵ�� 0~3֮�䡣
int byteSwap(int x, int n, int m);
//��������10
int byteSwap_standard(int x, int n, int m) {
    // �����ֽڵ�ƫ����
    int n_shift = n * 8;
    int m_shift = m * 8;

    // ��ȡ�� n ���ֽں͵� m ���ֽ�
    int n_byte = (x >> n_shift) & 0xFF;
    int m_byte = (x >> m_shift) & 0xFF;

    // ���� n �͵� m ���ֽ�λ������
    x = x & ~(0xFF << n_shift);  // ����� n ���ֽ�
    x = x & ~(0xFF << m_shift);  // ����� m ���ֽ�

    // �����ֽ�
    x = x | (n_byte << m_shift);  // ���� n ���ֽڷŵ��� m λ��
    x = x | (m_byte << n_shift);  // ���� m ���ֽڷŵ��� n λ��

    return x;
}


int main()
{
    int n, m, u;
    int x;
    int num, num1, num2;
    printf("1.����x�ľ���ֵ\n"
        "2.�����ø��ţ����� - x\n"
        "3.��ʹ�� ~ �� |��ʵ�� &\n"
        "4.��ʹ�� ~�� & ��ʵ��|\n"
        "5.��ʹ�� ~ �� &��ʵ�� ^\n"
        "6.�ж�x�Ƿ�Ϊ������������7FFFFFFF)\n"
        "7.ͳ��x�Ķ����Ʊ�ʾ�� 1 �ĸ���\n"
        "8.������lowbit��highbitȫΪ1 ����ȫΪ0����\n"
        "9.��x+y����������ʱ�򷵻�1�����򷵻�0\n"
        "10.��x�ĵ�n���ֽ����m���ֽڽ��������ؽ�����Ľ���� n��m��ȡֵ�� 0~3֮�䡣\n"
        "0.����0�˳�");
    while (1)
    {
        system("cls");
        printf("1.����x�ľ���ֵ\n"
            "2.�����ø��ţ����� - x\n"
            "3.��ʹ�� ~ �� |��ʵ�� &\n"
            "4.��ʹ�� ~�� & ��ʵ��|\n"
            "5.��ʹ�� ~ �� &��ʵ�� ^\n"
            "6.�ж�x�Ƿ�Ϊ������������7FFFFFFF)\n"
            "7.ͳ��x�Ķ����Ʊ�ʾ�� 1 �ĸ���\n"
            "8.������lowbit��highbitȫΪ1 ����ȫΪ0����\n"
            "9.��x+y����������ʱ�򷵻�1�����򷵻�0\n"
            "10.��x�ĵ�n���ֽ����m���ֽڽ��������ؽ�����Ľ���� n��m��ȡֵ�� 0~3֮�䡣\n"
            "0.����0�˳�\n");
        cin >> x;
        switch (x) {
        case 0:
            cout << "�����˳�����" << endl;
            break;
        case 1:
            cout << "������һ�������һ�ת��Ϊ����ֵ�����ƥ��...." << endl;
            cin >> num;
            cout << "�����ĺ�������ֵ�ǣ�" << absVal(num) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << absVal_standard(num) << endl;
            if (absVal(num) == absVal_standard(num))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 2:
            cout << "������һ�������һ�ת��Ϊ���������ƥ��...." << endl;
            cin >> num;
            cout << "�����ĺ�������ֵ�ǣ�" << netgate(num) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << netgate_standard(num) << endl;
            if (netgate(num) == netgate_standard(num))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 3:
            cout << "������2�������һ�ת��Ϊ��λ�������ƥ��...." << endl;
            cin >> num1 >> num2;
            cout << "�����ĺ�������ֵ�ǣ�" << bitAnd(num1, num2) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << bitAnd_standard(num1, num2) << endl;
            if (bitAnd(num1, num2) == bitAnd_standard(num1, num2))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 4:
            cout << "������2�������һ�ת��Ϊ��λ�������ƥ��...." << endl;
            cin >> num1 >> num2;
            cout << "�����ĺ�������ֵ�ǣ�" << bitOr(num1, num2) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << bitOr_standard(num1, num2) << endl;
            if (bitOr(num1, num2) == bitOr_standard(num1, num2))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 5:
            cout << "������2�������һ�ת��Ϊ��λ��������ƥ��...." << endl;
            cin >> num1 >> num2;
            cout << "�����ĺ�������ֵ�ǣ�" << bitXor(num1, num2) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << bitXor_standard(num1, num2) << endl;
            if (bitXor(num1, num2) == bitXor_standard(num1, num2))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 6:
            cout << "������һ�������һ��ж��ǲ���������������ƥ��...." << endl;
            cin >> num;
            cout << "�����ĺ�������ֵ�ǣ�" << isTmax(num) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << isTmax_standard(num) << endl;
            if (isTmax(num) == isTmax_standard(num))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 7:
            cout << "������һ�������һ�ͳ�ƶ�������1�ĸ�����ƥ��...." << endl;
            int num;
            cin >> num;
            cout << "�����ĺ�������ֵ�ǣ�" << bitCount(num) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << bitCount_standard(num) << endl;
            if (bitCount(num) == bitCount_standard(num))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 8:
            cout << "�һ�Ѵ�lowerbit��higherbit��ֵ���1��ƥ��...." << endl;
            cout << "������lowerbit��highbit\n";
            int l, h;
            cin >> l >> h;
            cout << "�����ĺ�������ֵ�ǣ�" << bitMask(l, h) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << bitMask_standard(l, h) << endl;
            if (bitMask(l, h) == bitMask_standard(l, h))
            {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 9:
            cout << "�һ��ж���������ӻ᲻�������ƥ��...." << endl;
            cout << "������2������\n";
            int num1, num2;
            cin >> num1 >> num2;
            cout << "�����ĺ�������ֵ�ǣ�" << addOK(num1, num2) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << addOK_standard(num1, num2) << endl;
            if (addOK(num1, num2) == addOK_standard(num1, num2)) {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        case 10:
            cout << "�һ��һ�����ĵ�n���ֽں͵�m���ֽڽ�����ƥ��...." << endl;
            cout << "������1������x����n��m\n";
            int x, n, m;
            cin >> x >> n >> m;
            cout << "�����ĺ�������ֵ�ǣ�" << byteSwap(x, n, m) << endl;
            cout << "�жϺ�������ֵ�ǣ�" << byteSwap_standard(x, n, m) << endl;
            if (byteSwap(x, n, m) == byteSwap_standard(x, n, m)) {
                cout << "ƥ��ɹ�" << endl;
            }
            break;
        }
        if (x == 0)
        {
            break;
        }
        else
        {
            system("pause");
        }
    }
    return 0;
}

int absVal(int x)
{
    return (x + (x >> 31)) ^ (x >> 31);
}

int netgate(int x)
{
    return (~x) + 1;
}

int bitAnd(int x, int y)
{
    return ~((~x) | (~y));
}


int bitOr(int x, int y)
{
    return ~((~x) & (~y));
}

int bitXor(int x, int y)
{
    return ~((~((~x) & y)) & (~(x & (~y))));
}


int isTmax(int x)
{
    return !(~(x + (1 << 31)));
}


int bitCount(int x) {
    // ��������
    int mask1 = 0x55 | (0x55 << 8);  // 01010101 01010101 (16-bit)
    mask1 = mask1 | (mask1 << 16);   // 01010101 01010101 01010101 01010101 (32-bit)

    int mask2 = 0x33 | (0x33 << 8);  // 00110011 00110011 (16-bit)
    mask2 = mask2 | (mask2 << 16);   // 00110011 00110011 00110011 00110011 (32-bit)

    int mask4 = 0x0F | (0x0F << 8);  // 00001111 00001111 (16-bit)
    mask4 = mask4 | (mask4 << 16);   // 00001111 00001111 00001111 00001111 (32-bit)

    int mask8 = 0xFF | (0xFF << 16); // 11111111 00000000 11111111 00000000 (32-bit)
    int mask16 = 0xFF | (0xFF << 8); // 00000000 11111111 00000000 11111111 (32-bit)

    // ��һ����ÿ����λͳ��һ��1�ĸ���
    x = (x & mask1) + ((x >> 1) & mask1);

    // �ڶ�����ÿ�ĸ�λͳ��һ��1�ĸ���
    x = (x & mask2) + ((x >> 2) & mask2);

    // ��������ÿ�˸�λͳ��һ��1�ĸ���
    x = (x & mask4) + ((x >> 4) & mask4);

    // ���Ĳ���ÿ16��λͳ��һ��1�ĸ���
    x = (x & mask8) + ((x >> 8) & mask8);

    // ���岽��ÿ32λͳ��һ��1�ĸ���
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}


int bitMask(int lowbit, int highbit) {
    // Step 1: ���ɴ� 0 �� highbit ȫΪ 1 ����
    int highMask = (1 << (highbit + 1)) - 1;

    // Step 2: �������룬ȥ�� lowbit ���µ�λ
    int lowMask = (1 << lowbit) - 1;

    // Step 3: ���������룬������ lowbit �� highbit �� 1
    return highMask & ~lowMask;
}


int addOK(int x, int y) {
    int sum = x + y;

    // ��ȡx��y�ķ���λ (����λ�ǵ�31λ)
    int x_sign = x >> 31;
    int y_sign = y >> 31;

    // ��ȡsum�ķ���λ
    int sum_sign = sum >> 31;

    // ��� x �� y �ķ�����ͬ���� sum �ķ����� x �� y �ķ��Ų�ͬ���������
    int overflow = !(x_sign ^ y_sign) & (x_sign ^ sum_sign);

    // ����������������1�����򷵻�0
    return overflow;
}


int byteSwap(int x, int n, int m)
{
    int p = ((x >> (n << 3)) ^ (x >> (m << 3))) & ((1 << 8) + (~0));
    return x ^ (((p) << (n << 3)) | ((p) << (m << 3)));
}