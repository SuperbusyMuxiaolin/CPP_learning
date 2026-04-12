#include <iostream>
#include "./head/myshared.hpp"

class Person
{
public:
    Person()
    {
        cout << "Person构造" << endl;
    }
    void demo()
    {
        cout << "demo调用" << endl;
    }
    ~Person()
    {
        cout << "Person析构" << endl;
    }
};
void test01()
{
    MySharedptr<Person> ptr1(new Person);
    cout << ptr1.ref->get_strongref() << endl;
    MySharedptr<Person> ptr2;
    ptr1 = ptr2;
}
int main()
{
    test01();
    return 0;
}