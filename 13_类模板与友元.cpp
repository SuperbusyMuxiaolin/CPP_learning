#include <iostream>
using namespace std;
// 前置声明Person类模板
template <class T1, class T2>
class Person;
// 全局函数类外实现声明，用到了类模板Person，所以要前置声明
template <class T1, class T2>
void printPerson2(Person<T1, T2> p);
template <class T1, class T2>
class Person
{
    // 全局函数-类内实现
    friend void printPerson(Person<T1, T2> p)
    {
        cout << "姓名：" << p.m_Name << endl;
        cout << "年龄：" << p.m_Age << endl;
    }

    // 全局函数-类外实现
    friend void printPerson2<T1, T2>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 全局函数类外实现
template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
    cout << "姓名：" << p.m_Name << endl;
    cout << "年龄：" << p.m_Age << endl;
}
// 全局函数类外实现的测试
void test02()
{
    Person<string, int> p("Jerry", 30);
    printPerson2(p);
}

// 全局函数类内实现的测试
void test01()
{
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

int main()
{
    // test01();
    test02();
    return 0;
}