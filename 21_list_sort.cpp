// 按年龄升序，年龄相同的身高越大越靠后
#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string name;
    int age;
    int height;
};

bool compare(Person &p1, Person &p2)
{
    if (p1.age == p2.age)
    {
        return p1.height < p2.height;
    }
    return p1.age < p2.age;
}

void printlist(list<Person> &ls)
{
    for (list<Person>::iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << "身高为：" << it->height << "\t年龄为:" << it->age << "\t姓名为：" << it->name << endl;
    }
}

void test01()
{
    list<Person> L;

    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_front(p1);
    L.push_front(p2);
    L.push_front(p3);
    L.push_front(p4);
    L.push_front(p5);

    printlist(L);
    L.sort(compare);
    cout << "--------------------" << endl;
    printlist(L);
}

int main()
{
    test01();
    return 0;
}
