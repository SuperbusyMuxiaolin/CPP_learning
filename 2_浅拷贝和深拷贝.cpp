#include<iostream>

class Person{  
    public:
        Person(int age, int height){
            m_Age =age;
            m_Height= new int(height);
            std::cout<<"带参数构造"<<std::endl;

        }
        // 深拷贝
        Person(const Person &p){
            m_Age = p.m_Age;
            m_Height = new int(*p.m_Height);
            std::cout<<"深拷贝"<<std::endl;

        }
        ~Person(){
            if(m_Height != NULL){
                delete m_Height;
            }
            std::cout<<"析构函数"<<std::endl;
        }

        int m_Age;
        int* m_Height;

};

int main(){
    Person p1(18, 170);
    Person p2(p1);
    return 0;
}

