#include <iostream>
using namespace std;



class Building{
    public:
        Building(){
            this->m_SittingRoom = "客厅";
            this->m_BedRoom = "卧室";
        }
        //声明友元类
        friend class goodGay;
        //声明全局函数是Building的友元函数
        friend void visitgoodGay(Building *building);
    public:
        string m_SittingRoom;
    private:
        string m_BedRoom;
};

class goodGay{

    Building bu;
    public:
        void visit(){
            cout<<"正在访问"<<bu.m_SittingRoom<<endl;
            cout<<"正在访问"<<bu.m_BedRoom<<endl;
        }

};

void visitgoodGay(Building *building){
    cout<<"访问building的"<<building->m_SittingRoom<<endl;
    cout<<"访问building的"<<building->m_BedRoom<<endl;
}



void test01(){
    Building b;
    visitgoodGay(&b);
}
void test02(){
    class goodGay g;
    g.visit();
}

int main(){
    test01();
    test02();
    return 0;
}