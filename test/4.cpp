#include<iostream>
using namespace std;

class Book{
    public:
        int price = 20;
        mutable int visitcount = 0;

        void showprice() const{
            //this->price=10;
            this->visitcount++;
        }
        void setPrice(int p){

        }
        int getPrice() const{
            return this->price;
        }

};

int main(){
    Book b;
    const Book cb;
    b.setPrice(20);
    b.getPrice();
    cb.setPrice(30);
    cb.getPrice();
}


