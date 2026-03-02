#include<iostream>
using namespace std;

class Counter{
    public:
        int count = 0;
        Counter& add(int x){
            this->count += x;
            return *this;
        }


};

int main(){
    Counter c;
    cout<<c.add(3).add(4).count<<endl;
}