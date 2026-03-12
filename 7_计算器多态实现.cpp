#include<iostream>
using namespace std;


class Abstractcalculator{
    public:
        virtual int get_result(){
            return 0;
        }
        int m_num1;
        int m_num2;
};

class Add : public Abstractcalculator{
    int get_result(){
        return m_num1+m_num2;
    }
};

class Sub : public Abstractcalculator{
    int get_result(){
        return m_num1-m_num2;
    }
};
class Mul : public Abstractcalculator{
    public:
        int get_result(){
            return m_num1*m_num2;
        }
};

void test01(){
    Abstractcalculator * cal = new Mul;
    cal->m_num1=10;
    cal->m_num2=10;
    cout<<cal->get_result()<<endl;
    delete cal;
}


int main(){
    test01();
    return 0;
}