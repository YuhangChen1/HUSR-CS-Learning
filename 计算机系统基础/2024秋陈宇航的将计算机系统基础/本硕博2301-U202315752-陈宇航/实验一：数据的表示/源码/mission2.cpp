
#include<bits/stdc++.h>

using namespace std;

//1.返回x的绝对值
int absVal(int x);

//评定函数1
int absVal_standard(int x) { return (x < 0) ? -x : x; }

//2.不适用负号，返回-x
int netgate(int x);
//评定函数2
int netgate_standard(int x) { return -x; }

//3.(3)仅使用 ~ 和 |，实现 &
int bitAnd(int x, int y);
//评定函数3
int bitAnd_standard(int x, int y) { return x & y; }


//4.仅使用 ~和 & ，实现|
int bitOr(int x, int y);
//评定函数4
int bitOr_standard(int x, int y) { return x | y; }

//5.(5)仅使用 ~ 和 &，实现 ^
int bitXor(int x, int y);
//评定函数5
int bitXor_standard(int x, int y) { return x ^ y; }


//6.判断x是否为最大的正整数（7FFFFFFF）
int isTmax(int x);
//判断函数6
int isTmax_standard(int x) { return x == 0x7FFFFFFF; }

//7.统计x的二进制表示中 1 的个数
int bitCount(int x);
//判断函数7
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


//8.产生从lowbit到highbit全为1 其他全为0的数
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


//9.当x+y会产生溢出的时候返回1，否则返回0
int addOK(int x, int y);
int addOK_standard(int x, int y)
{
    long long lsum = (long long)(x + y);
    return !(lsum == (int)lsum);
}


//10.将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间。
int byteSwap(int x, int n, int m);
//评定函数10
int byteSwap_standard(int x, int n, int m) {
    // 计算字节的偏移量
    int n_shift = n * 8;
    int m_shift = m * 8;

    // 提取第 n 个字节和第 m 个字节
    int n_byte = (x >> n_shift) & 0xFF;
    int m_byte = (x >> m_shift) & 0xFF;

    // 将第 n 和第 m 个字节位置清零
    x = x & ~(0xFF << n_shift);  // 清零第 n 个字节
    x = x & ~(0xFF << m_shift);  // 清零第 m 个字节

    // 交换字节
    x = x | (n_byte << m_shift);  // 将第 n 个字节放到第 m 位置
    x = x | (m_byte << n_shift);  // 将第 m 个字节放到第 n 位置

    return x;
}


int main()
{
    int n, m, u;
    int x;
    int num, num1, num2;
    printf("1.返回x的绝对值\n"
        "2.不适用负号，返回 - x\n"
        "3.仅使用 ~ 和 |，实现 &\n"
        "4.仅使用 ~和 & ，实现|\n"
        "5.仅使用 ~ 和 &，实现 ^\n"
        "6.判断x是否为最大的正整数（7FFFFFFF)\n"
        "7.统计x的二进制表示中 1 的个数\n"
        "8.产生从lowbit到highbit全为1 其他全为0的数\n"
        "9.当x+y会产生溢出的时候返回1，否则返回0\n"
        "10.将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间。\n"
        "0.输入0退出");
    while (1)
    {
        system("cls");
        printf("1.返回x的绝对值\n"
            "2.不适用负号，返回 - x\n"
            "3.仅使用 ~ 和 |，实现 &\n"
            "4.仅使用 ~和 & ，实现|\n"
            "5.仅使用 ~ 和 &，实现 ^\n"
            "6.判断x是否为最大的正整数（7FFFFFFF)\n"
            "7.统计x的二进制表示中 1 的个数\n"
            "8.产生从lowbit到highbit全为1 其他全为0的数\n"
            "9.当x+y会产生溢出的时候返回1，否则返回0\n"
            "10.将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间。\n"
            "0.输入0退出\n");
        cin >> x;
        switch (x) {
        case 0:
            cout << "正在退出程序" << endl;
            break;
        case 1:
            cout << "请输入一个数，我会转化为绝对值输出并匹配...." << endl;
            cin >> num;
            cout << "建立的函数返回值是：" << absVal(num) << endl;
            cout << "判断函数返回值是：" << absVal_standard(num) << endl;
            if (absVal(num) == absVal_standard(num))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 2:
            cout << "请输入一个数，我会转化为负数输出并匹配...." << endl;
            cin >> num;
            cout << "建立的函数返回值是：" << netgate(num) << endl;
            cout << "判断函数返回值是：" << netgate_standard(num) << endl;
            if (netgate(num) == netgate_standard(num))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 3:
            cout << "请输入2个数，我会转化为按位与输出并匹配...." << endl;
            cin >> num1 >> num2;
            cout << "建立的函数返回值是：" << bitAnd(num1, num2) << endl;
            cout << "判断函数返回值是：" << bitAnd_standard(num1, num2) << endl;
            if (bitAnd(num1, num2) == bitAnd_standard(num1, num2))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 4:
            cout << "请输入2个数，我会转化为按位或输出并匹配...." << endl;
            cin >> num1 >> num2;
            cout << "建立的函数返回值是：" << bitOr(num1, num2) << endl;
            cout << "判断函数返回值是：" << bitOr_standard(num1, num2) << endl;
            if (bitOr(num1, num2) == bitOr_standard(num1, num2))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 5:
            cout << "请输入2个数，我会转化为按位异或输出并匹配...." << endl;
            cin >> num1 >> num2;
            cout << "建立的函数返回值是：" << bitXor(num1, num2) << endl;
            cout << "判断函数返回值是：" << bitXor_standard(num1, num2) << endl;
            if (bitXor(num1, num2) == bitXor_standard(num1, num2))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 6:
            cout << "请输入一个数，我会判断是不是最大正数输出并匹配...." << endl;
            cin >> num;
            cout << "建立的函数返回值是：" << isTmax(num) << endl;
            cout << "判断函数返回值是：" << isTmax_standard(num) << endl;
            if (isTmax(num) == isTmax_standard(num))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 7:
            cout << "请输入一个数，我会统计二进制中1的个数并匹配...." << endl;
            int num;
            cin >> num;
            cout << "建立的函数返回值是：" << bitCount(num) << endl;
            cout << "判断函数返回值是：" << bitCount_standard(num) << endl;
            if (bitCount(num) == bitCount_standard(num))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 8:
            cout << "我会把从lowerbit到higherbit的值变成1并匹配...." << endl;
            cout << "请输入lowerbit和highbit\n";
            int l, h;
            cin >> l >> h;
            cout << "建立的函数返回值是：" << bitMask(l, h) << endl;
            cout << "判断函数返回值是：" << bitMask_standard(l, h) << endl;
            if (bitMask(l, h) == bitMask_standard(l, h))
            {
                cout << "匹配成功" << endl;
            }
            break;
        case 9:
            cout << "我会判断两个数想加会不会溢出并匹配...." << endl;
            cout << "请输入2个数字\n";
            int num1, num2;
            cin >> num1 >> num2;
            cout << "建立的函数返回值是：" << addOK(num1, num2) << endl;
            cout << "判断函数返回值是：" << addOK_standard(num1, num2) << endl;
            if (addOK(num1, num2) == addOK_standard(num1, num2)) {
                cout << "匹配成功" << endl;
            }
            break;
        case 10:
            cout << "我会把一个数的第n个字节和第m个字节交换并匹配...." << endl;
            cout << "请输入1个数字x，和n，m\n";
            int x, n, m;
            cin >> x >> n >> m;
            cout << "建立的函数返回值是：" << byteSwap(x, n, m) << endl;
            cout << "判断函数返回值是：" << byteSwap_standard(x, n, m) << endl;
            if (byteSwap(x, n, m) == byteSwap_standard(x, n, m)) {
                cout << "匹配成功" << endl;
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
    // 定义掩码
    int mask1 = 0x55 | (0x55 << 8);  // 01010101 01010101 (16-bit)
    mask1 = mask1 | (mask1 << 16);   // 01010101 01010101 01010101 01010101 (32-bit)

    int mask2 = 0x33 | (0x33 << 8);  // 00110011 00110011 (16-bit)
    mask2 = mask2 | (mask2 << 16);   // 00110011 00110011 00110011 00110011 (32-bit)

    int mask4 = 0x0F | (0x0F << 8);  // 00001111 00001111 (16-bit)
    mask4 = mask4 | (mask4 << 16);   // 00001111 00001111 00001111 00001111 (32-bit)

    int mask8 = 0xFF | (0xFF << 16); // 11111111 00000000 11111111 00000000 (32-bit)
    int mask16 = 0xFF | (0xFF << 8); // 00000000 11111111 00000000 11111111 (32-bit)

    // 第一步：每两个位统计一次1的个数
    x = (x & mask1) + ((x >> 1) & mask1);

    // 第二步：每四个位统计一次1的个数
    x = (x & mask2) + ((x >> 2) & mask2);

    // 第三步：每八个位统计一次1的个数
    x = (x & mask4) + ((x >> 4) & mask4);

    // 第四步：每16个位统计一次1的个数
    x = (x & mask8) + ((x >> 8) & mask8);

    // 第五步：每32位统计一次1的个数
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}


int bitMask(int lowbit, int highbit) {
    // Step 1: 生成从 0 到 highbit 全为 1 的数
    int highMask = (1 << (highbit + 1)) - 1;

    // Step 2: 生成掩码，去掉 lowbit 以下的位
    int lowMask = (1 << lowbit) - 1;

    // Step 3: 将两者相与，保留从 lowbit 到 highbit 的 1
    return highMask & ~lowMask;
}


int addOK(int x, int y) {
    int sum = x + y;

    // 获取x和y的符号位 (符号位是第31位)
    int x_sign = x >> 31;
    int y_sign = y >> 31;

    // 获取sum的符号位
    int sum_sign = sum >> 31;

    // 如果 x 和 y 的符号相同，且 sum 的符号与 x 或 y 的符号不同，则发生溢出
    int overflow = !(x_sign ^ y_sign) & (x_sign ^ sum_sign);

    // 如果发生溢出，返回1，否则返回0
    return overflow;
}


int byteSwap(int x, int n, int m)
{
    int p = ((x >> (n << 3)) ^ (x >> (m << 3))) & ((1 << 8) + (~0));
    return x ^ (((p) << (n << 3)) | ((p) << (m << 3)));
}