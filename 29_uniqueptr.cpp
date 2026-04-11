#include <iostream>
#include <memory>
using namespace std;
#include <vector>
#include <functional>

class Person
{
public:
    Person()
    {
        cout << "构造函数" << endl;
    }
    void Demo()
    {
        cout << "Person Demo" << endl;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

// 基础使用
void test01()
{
    unique_ptr<Person> up1(new Person);
    // up1->Demo();

    // unique_ptr<Person[]> up2(new Person[2]);
    // up2[0].Demo();
    // up2[1].Demo();

    Person *person_ptr1 = up1.get();
    // Person *person_ptr2 = up1.release();
    // up1.reset();
    up1.reset(new Person);
}

void test02()
{
    unique_ptr<Person> up1(new Person);
    unique_ptr<Person> up2(new Person);

    unique_ptr<Person> up3 = move(up1);
    // up3 = up2;
    up3 = move(up2);
    vector<unique_ptr<Person>> v;
    // v.push_back(up1); 容器要求元素可以拷贝
}

class Deleter
{
public:
    void operator()(FILE *file)
    {
        cout << "文件被自动关闭" << endl;
        if (file != nullptr)
        {
            fclose(file);
            file = nullptr;
        }
    }
};

void fun_delete(FILE *file)
{
    cout << "文件被自动关闭" << endl;
    if (file != nullptr)
    {
        fclose(file);
        file = nullptr;
    }
}

// 自定义deleter
void test03()
{
    // unique_ptr<FILE, Deleter> up(fopen("./demo.txt", "w"), Deleter());
    // unique_ptr<FILE, function<void(FILE *)>> up(fopen("./demo.txt", "w"), Deleter());
    unique_ptr<FILE, function<void(FILE *)>> up(fopen("./demo.txt", "w"), fun_delete);
    if (!up)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fputs("hello world\n", up.get());
}

int main()
{
    test03();
}