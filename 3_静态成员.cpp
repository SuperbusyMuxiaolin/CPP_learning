#include<iostream>

class Person{
    public:
        //静态成员变量
        static int m_A;
        //静态成员函数，只能访问静态成员变量
        static void func(){
              
        }

};
int Person::m_A = 10;

void test01(){
    Person p;
    std::cout<<p.m_A<<std::endl; 
    Person p2;
    p2.m_A=20;
    std::cout<<p.m_A<<std::endl; 
    std::cout<<Person::m_A<<std::endl;
}
void test02(){
    Person::func();
    Person p;
    p.func();
}

int main(){
    test01();
    test02();
    return 0;
}