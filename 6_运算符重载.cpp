#include<iostream>
using namespace std;

class Person{
    public:
        Person(int a, int b);
        Person operator+(Person &b);
        //Person& operator++();
        //Person operator++(int);
        Person& operator=(Person &p);
    //friend Person operator+(Person &a, Person &b);
    friend std::ostream& operator<<(std::ostream &cout, const Person &p);
    friend Person& operator++(Person &p);
    friend Person operator++(Person &p, int);
    private:
        int m_A;
        int m_B;
    public:
        int* m_p;
};

Person::Person(int a=0,int b=0){
    m_A=a;
    m_B=b;
    m_p=new int(10);
}
//成员函数加法运算符重载
Person Person::operator+(Person &b){
    Person temp(0,0);
    temp.m_A = this->m_A + b.m_A;
    temp.m_B = this->m_B + b.m_B;
    return temp;
}
//成员函数前置递增重载
// Person& Person::operator++(){
//     this->m_A++;
//     this->m_B++;
//     return *this;
// }

//成员函数后置递增重载
// Person Person::operator++(int){
//     Person temp = *this;
//     this->m_A++;
//     this->m_B++;
//     return temp;
// }

//成员函数赋值运算符重载
Person& Person::operator=(Person &p){
    this->m_A=p.m_A;
    this->m_B=p.m_B;
    if(this->m_p!=NULL){
        delete this->m_p;
        this->m_p=NULL;
    }
    this->m_p= new int(*p.m_p);
    return*this;
}



// 全局函数加法运算符重载
// Person operator+(Person &a, Person &b){
//     Person temp(0,0);
//     temp.m_A = a.m_A + b.m_A;
//     temp.m_B = a.m_B + b.m_B;
//     return temp;
// }

// 左移运算符重载
std::ostream& operator<<(std::ostream &cout, const Person &p){
    cout<<p.m_A<<endl;
    cout<<p.m_B<<endl;
    return cout;
}

// 全局函数前置递增重载
Person& operator++(Person &p){
    p.m_A++;
    p.m_B++;
    return p;
}

Person operator++(Person &p, int){
    Person temp = p;
    p.m_A++;
    p.m_B++;
    return temp;
}



// void test01(){
//     Person p1(10,20);
//     Person p2(10,20);
//     Person p3 = p1 + p2 +p2;
//     cout<<p3.m_A<<endl;
//     cout<<p3.m_B<<endl;
// }

void test02(){
    Person p1;
    cout<<p1<<p1<<endl;
}
void test03(){
    Person p1;
    cout<<p1++<<endl;
}
void test04(){
    Person p1(10,20);
    Person p2;
    p2 = p1;
    cout<<p1.m_p<<endl;
    cout<<p2.m_p<<endl;
}


int main(){
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}