#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int>::iterator it_f = find(v1.begin(), v1.end(), 5);
    if (it_f != v1.end())
    {
        cout << "找到了元素:" << *it_f << endl;
        return;
    }
    cout << "未找到" << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // 这里要用const，因为find函数里面有这个要求
    bool operator==(const Person &p)
    {
        return this->name == p.name && this->age == p.age;
    }
    string name;
    int age;
};

// class equalPerson
// {
//     bool operator()(const Person &p1, const Person &p2)
//     {
//         return p1.name == p2.name && p1.age == p2.age;
//     }
// };

void test02()
{
    vector<Person> v2;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    vector<Person>::iterator it_f = find(v2.begin(), v2.end(), Person("ccc", 30));
    if (it_f != v2.end())
    {
        cout << "找到了元素:" << it_f->age << it_f->name << endl;
        return;
    }
    cout << "未找到" << endl;
}

class Greater30
{
public:
    bool operator()(const Person &p)
    {
        return p.age > 30;
    }
};

void test03()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater30());
    if (it != v.end())
    {
        cout << "找到了元素:" << it->age << it->name << endl;
        return;
    }
    cout << "未找到" << endl;
}

int main()
{
    test03();
}
