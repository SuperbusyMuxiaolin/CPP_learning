#include <iostream>
using namespace std;

class Building;

class goodGay{
    public:
        Building* b = nullptr;
    public:
        void visit01();
        void visit02();
};
class Building{
    public:
        Building();
        //声明成员函数做友元
        friend void goodGay::visit01();
    public:
        string m_SittingRoom;
    private:
        string m_BedRoom;
};


void goodGay::visit01(){
    cout<<"正在访问"<<b->m_SittingRoom<<endl;
    cout<<"正在访问"<<b->m_BedRoom<<endl;
}
void goodGay::visit02(){
    cout<<"正在访问"<<b->m_SittingRoom<<endl;
    //cout<<"正在访问"<<b->m_BedRoom<<endl;
}

Building::Building(){
            this->m_SittingRoom = "客厅";
            this->m_BedRoom = "卧室";
        }

int main(){
    goodGay gg;
    Building bb;
    gg.b = &bb;
    gg.visit01();
    gg.visit02();
    return 0;
}