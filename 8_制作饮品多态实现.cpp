#include<iostream>

using namespace std;

class AbstractMakingDrink{
    public:
        virtual void boil()=0;
        virtual void add()=0;
        virtual void putother_thing()=0;
        void make_drink(){
            boil();
            add();
            putother_thing();
        }
};

class Coffee :public AbstractMakingDrink{
    void boil(){
        cout<<"烧开水"<<endl;
    }
    void add(){
        cout<<"加入咖啡"<<endl;
    }
    void putother_thing(){
        cout<<"加入牛奶和糖"<<endl;
    }
};


class Tea :public AbstractMakingDrink{
    void boil(){
        cout<<"烧开水"<<endl;
    }
    void add(){
        cout<<"加入茶叶"<<endl;
    }
    void putother_thing(){
        cout<<"加入柠檬"<<endl;
    }
};

void dowork(AbstractMakingDrink &abs){
    abs.make_drink();
}

void test01(){
    Coffee co;
    dowork(co);
}

int main(){
    test01();
    return 0;
}