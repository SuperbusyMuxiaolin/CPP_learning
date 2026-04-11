#include <iostream>
using namespace std;
#include <memory>
class Person
{
public:
    Person()
    {
        cout << "Person 构造函数" << endl;
    }
    ~Person()
    {
        cout << "Person 析构函数" << endl;
    }
};
void test01()
{
    shared_ptr<Person> sp1(new Person);
    shared_ptr<Person[]> sp2(new Person[2]);
    shared_ptr<Person> sp3(new Person);

    Person *person = sp1.get();

    sp1.swap(sp3);
    sp1.reset(); // 引用次数减1
}
void test02()
{
    shared_ptr<Person> sp1(new Person);
    shared_ptr<Person> sp2(sp1);
    shared_ptr<Person> sp3;
    sp3 = sp1;

    shared_ptr<Person> sp4(move(sp1));
    shared_ptr<Person> sp5;
    sp5 = move(sp2);
    sp3.reset();
    cout << sp1.get() << endl;
    cout << sp2.get() << endl;
    cout << sp3.get() << endl;
    cout << sp4.get() << endl;
    cout << sp5.get() << endl;

    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
    cout << sp4.use_count() << endl;
    cout << sp5.use_count() << endl;
}

class mydeleter
{
public:
    void operator()(FILE *file)
    {
        cout << "函数对象文件自动关闭" << endl;
        if (file != nullptr)
        {
            fclose(file);
        }
        file = nullptr;
    }
};

void mydeleterfun(FILE *file)
{
    cout << "函数文件自动关闭" << endl;
    if (file != nullptr)
    {
        fclose(file);
    }
    file = nullptr;
}

auto lam = [](FILE *file)
{
    cout << "lam文件自动关闭" << endl;
    if (file != nullptr)
    {
        fclose(file);
    }
    file = nullptr;
};

void test03()
{
    shared_ptr<FILE> sp1(fopen("./demo.txt", "w"), mydeleter());
    shared_ptr<FILE> sp2(fopen("./demo.txt", "w"), mydeleterfun);
    shared_ptr<FILE> sp3(fopen("./demo.txt", "w"), lam);
}
int main()
{
    test03();
}