#include <iostream>
using namespace std;

// 初始化与赋值
void test01()
{
    string s1("hhhh");
    cout << s1 << endl;

    string s2(s1);
    cout << s2 << endl;

    string s3(5, 'x');
    cout << s3 << endl;

    string s4 = s1;
    cout << s4 << endl;
    string s5 = "hello world";
    cout << s5 << endl;
    string s6;
    s6 = 't';
    cout << s6 << endl;
    string s7;
    s7.assign(s5);
    cout << s7 << endl;
    string s8;
    s8.assign("hhhhhhh");
    cout << s8 << endl;
    s8.assign("hhhhh", 3);
    cout << s8 << endl;
    string s9;
    s9.assign(6, 'x');
    cout << s9 << endl;
}
// 字符串拼接
void test02()
{
    string s1 = "我爱玩";
    s1 += "游戏";
    cout << s1 << endl;
    s1 += 'A';
    cout << s1 << endl;
    string s2 = "王者荣耀";
    s1 += s2;
    cout << s1 << endl;

    string s3 = "我爱玩";
    s3.append("游戏");
    cout << s3 << endl;
    s3.append("aaaaa", 3);
    cout << s3 << endl;
    s3.append(s2);
    cout << s3 << endl;
    s3.append("tatttttt", 1, 3);
    cout << s3 << endl;
}

// 查找和替换
void test03()
{
    string str1 = "abcdebc";
    int index = str1.find("bc");
    cout << "查到的bc索引" << index << endl;

    int index2 = str1.rfind("bc");
    cout << "逆序查到的bc索引" << index2 << endl;

    // 替换
    str1.replace(1, 3, "hhhhh");
    cout << "替换后的str1:" << str1 << endl;
}

void test04()
{
    string str1 = "cdc";
    string str2 = "bbc";

    cout << "比较返回的值：" << str1.compare(str2) << endl;
}

void test05()
{
    // 通过[]访问某一个字符
    string s1 = "abcd";
    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
    s1[2] = 'k';
    cout << s1 << endl;
}

void test06()
{
    string s1 = "abcde";
    s1.insert(1, "hhh");
    cout << s1 << endl;
    s1.erase(1, 3);
    cout << s1 << endl;
}

void test07()
{
    string s1 = "abcde";
    string s2 = s1.substr(1, 3);
    cout << s2 << endl;

    string s3 = "hhhh@gamil.com";
    int pos = s3.find('@');
    string s4 = s3.substr(0, pos);
    cout << s4 << endl;
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test07();
    return 0;
}