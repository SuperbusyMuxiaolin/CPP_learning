#include <iostream>
using namespace std;

int myADD(int a, int b)
{
    return a + b;
}

template <typename T>
T add2(T a, T b)
{
    return a + b;
}

template <typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void myprint(int a, int b)
{
    cout << "普通" << endl;
}

template <typename T>
void myprint(T a, T b)
{
    cout << "模板" << endl;
}

template <class T1, class T2> // 有成员，成员的类型可以先不指定，用T1和T2代替, 可以有默认参数
class Person
{
public:
    Person(T1 t1, T2 t2)
    {
        name = t1;
        age = t2;
    }

    void showperson()
    {
        cout << name << age << endl;
    }
    T1 name;
    T2 age;
};

class Person1
{
public:
    void showperson1()
    {
        cout << "shouperson1" << endl;
    }
};

class Person2
{
public:
    void showperson2()
    {
        cout << "shouperson2" << endl;
    }
};
template <class T>
class Myclass
{
public:
    void fun1()
    {
        obj.showperson1();
    }
    void fun2()
    {
        obj.showperson2();
    }
    T obj;
};

void test01()
{
    int a = 10;
    int b = 20;
    myswap(a, b);
    cout << a << b << endl;
    myswap<int>(a, b);
    cout << a << b << endl;
}

void test02()
{
    // 普通函数有隐式自动转换
    int a = 10;
    char c = 'c';
    cout << myADD(a, c) << endl;
    // cout << add2(a, c) << endl; 错误，不能隐式转换
    cout << add2<int>(a, c) << endl;
}

void test03()
{
    int a = 10;
    int b = 20;
    myprint(a, b);
    myprint<>(a, b);
}

void test04()
{
    Person<string, int> p1("zhangsan", 99);
    cout << p1.age << p1.name << endl;
}

void test05()
{
    // 类模板没有自动类型推导,只能显式指定类型
    // Person p2("zhangsan", 99)
}

void test06()
{

    Person<string, int> p3("zhangsan", 99);
}

void test07()
{
    Myclass<Person1> my;
    my.fun1();
    // my.fun2();
}
void print1(Person<string, int> &p)
{
    p.showperson();
}
template <class T1, class T2>
void print2(Person<T1, T2> &p)
{
    p.showperson();
}

template <class T>
void print3(T &p)
{
    p.showperson();
}
void test08()
{
    Person<string, int> p("张三", 20);
    // print1(p);
    print2(p);
    print3(p);
}

template <class T>
class Base
{
public:
    T m;
};
// 需要指定类模板的参数
class son : public Base<int>
{
};
// 如果想灵活指定父类的T，子类也要变成类模板

template <class T1, class T2>
class son2 : public Base<T2>
{
    T1 k;
};

void test09()
{
    son2<int, char> s;
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test07();
    // test08();
    // test09();
    return 0;
}