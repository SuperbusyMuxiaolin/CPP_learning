#include <iostream>
using namespace std;

void printall()
{
    cout << endl;
}

template <typename T, typename... Args>
void printall(const T &first, const Args &...args)
{
    cout << first << "  ";
    printall(args...);
}
void test01()
{
    printall(1, 2.5, "hello");
}

template <typename... Args>
void coutall1(Args... args)
{
    (cout << ... << args) << endl;
}

template <typename... Args>
void coutall2(Args... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}

void test02()
{
    coutall2(1, 2.5, "hello");
}
int main()
{
    test02();
}