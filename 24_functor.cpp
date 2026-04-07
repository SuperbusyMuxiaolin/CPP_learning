#include <iostream>
using namespace std;

class Myadd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class Myprint
{
public:
    Myprint()
    {
        count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        count++;
    }

    int count;
};

void test01()
{
    Myadd md;
    cout << md(10, 20) << endl;
}
void test02()
{
    Myprint mp;
    mp("hhhh");
    mp("hhhh");
    mp("hhhh");
    cout << mp.count << endl;
}
void doprint(Myprint &mp, string t)
{
    mp(t);
}
void test03()
{
    Myprint mp;
    string x = "hhh";
    doprint(mp, x);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}