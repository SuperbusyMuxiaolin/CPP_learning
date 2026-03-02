#include<iostream>
using namespace std;

class Person{
    public:
        int age;
        Person(int age){
            this->age=age;
        }

};
int main(){
    Person p(10);
    cout<<p.age<<endl;
}